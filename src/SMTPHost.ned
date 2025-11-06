package peyal;

simple SMTPClient {
    parameters:
        string address;
        double sendInterval @unit(s);
        double initialTrustScore;
        @display("i=block/app2_l");
    gates:
        input in;
        output out;
}

simple SMTPServer {
    parameters:
        string address;
        @display("i=block/server");
    gates:
        input in[];
        output out[];
}

simple TrustManager {
    parameters:
        double dropThreshold @unit() = 0.3;
        @display("i=block/filter_l");
    gates:
        input in[];
        output out[];
}

network TrustSMTPNetwork {
    types:
        channel SimpleChannel extends ned.DatarateChannel {
            datarate = 100Mbps;
            delay = 1ms;
            @display("ls=blue,3");
        }

    submodules:
        hostA: SMTPClient {
            parameters:
                address = "hostA";
                initialTrustScore = 0.9;
                sendInterval = 4s;
            @display("p=100,200;i=block/app2_l;is=email");
        }


        srvA: SMTPServer {
            parameters:
                address = "hostA";
            @display("p=200,200;i=block/server;is=server");
            gates:
                in[2];
                out[2];
        }


        tm: TrustManager {
            @display("p=300,200;i=block/filter_l;is=firewall");
            gates:
                in[2];
                out[2];
        }


        srvB: SMTPServer {
            parameters:
                address = "hostB";
            @display("p=400,200;i=block/server;is=server");
            gates:
                in[2];
                out[2];
        }


        hostB: SMTPClient {
            parameters:
                address = "hostB";
                initialTrustScore = 0.2;
                sendInterval = 2s;
            @display("p=500,200;i=block/app2_l;is=email");
        }

    connections:

        hostA.out --> SimpleChannel --> srvA.in[0];
        srvA.out[0] --> SimpleChannel --> tm.in[0];
        tm.out[0] --> SimpleChannel --> srvB.in[0];
        srvB.out[0] --> SimpleChannel --> hostB.in;


        hostB.out --> SimpleChannel --> srvB.in[1];
        srvB.out[1] --> SimpleChannel --> tm.in[1];
        tm.out[1] --> SimpleChannel --> srvA.in[1];
        srvA.out[1] --> SimpleChannel --> hostA.in;
}