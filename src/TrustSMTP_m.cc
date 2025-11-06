//
// Generated file, do not edit! Created by opp_msgtool 6.2 from TrustSMTP.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wshadow"
#  pragma clang diagnostic ignored "-Wconversion"
#  pragma clang diagnostic ignored "-Wunused-parameter"
#  pragma clang diagnostic ignored "-Wc++98-compat"
#  pragma clang diagnostic ignored "-Wunreachable-code-break"
#  pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined(__GNUC__)
#  pragma GCC diagnostic ignored "-Wshadow"
#  pragma GCC diagnostic ignored "-Wconversion"
#  pragma GCC diagnostic ignored "-Wunused-parameter"
#  pragma GCC diagnostic ignored "-Wold-style-cast"
#  pragma GCC diagnostic ignored "-Wsuggest-attribute=noreturn"
#  pragma GCC diagnostic ignored "-Wfloat-conversion"
#endif

#include <iostream>
#include <sstream>
#include <memory>
#include <type_traits>
#include "TrustSMTP_m.h"

namespace omnetpp {

// Template pack/unpack rules. They are declared *after* a1l type-specific pack functions for multiple reasons.
// They are in the omnetpp namespace, to allow them to be found by argument-dependent lookup via the cCommBuffer argument

// Packing/unpacking an std::vector
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::vector<T,A>& v)
{
    int n = v.size();
    doParsimPacking(buffer, n);
    for (int i = 0; i < n; i++)
        doParsimPacking(buffer, v[i]);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::vector<T,A>& v)
{
    int n;
    doParsimUnpacking(buffer, n);
    v.resize(n);
    for (int i = 0; i < n; i++)
        doParsimUnpacking(buffer, v[i]);
}

// Packing/unpacking an std::list
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::list<T,A>& l)
{
    doParsimPacking(buffer, (int)l.size());
    for (typename std::list<T,A>::const_iterator it = l.begin(); it != l.end(); ++it)
        doParsimPacking(buffer, (T&)*it);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::list<T,A>& l)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        l.push_back(T());
        doParsimUnpacking(buffer, l.back());
    }
}

// Packing/unpacking an std::set
template<typename T, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::set<T,Tr,A>& s)
{
    doParsimPacking(buffer, (int)s.size());
    for (typename std::set<T,Tr,A>::const_iterator it = s.begin(); it != s.end(); ++it)
        doParsimPacking(buffer, *it);
}

template<typename T, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::set<T,Tr,A>& s)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        T x;
        doParsimUnpacking(buffer, x);
        s.insert(x);
    }
}

// Packing/unpacking an std::map
template<typename K, typename V, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::map<K,V,Tr,A>& m)
{
    doParsimPacking(buffer, (int)m.size());
    for (typename std::map<K,V,Tr,A>::const_iterator it = m.begin(); it != m.end(); ++it) {
        doParsimPacking(buffer, it->first);
        doParsimPacking(buffer, it->second);
    }
}

template<typename K, typename V, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::map<K,V,Tr,A>& m)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        K k; V v;
        doParsimUnpacking(buffer, k);
        doParsimUnpacking(buffer, v);
        m[k] = v;
    }
}

// Default pack/unpack function for arrays
template<typename T>
void doParsimArrayPacking(omnetpp::cCommBuffer *b, const T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimPacking(b, t[i]);
}

template<typename T>
void doParsimArrayUnpacking(omnetpp::cCommBuffer *b, T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimUnpacking(b, t[i]);
}

// Default rule to prevent compiler from choosing base class' doParsimPacking() function
template<typename T>
void doParsimPacking(omnetpp::cCommBuffer *, const T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimPacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

template<typename T>
void doParsimUnpacking(omnetpp::cCommBuffer *, T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimUnpacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

}  // namespace omnetpp

namespace peyal {

Register_Class(TrustSMTPMessage)

TrustSMTPMessage::TrustSMTPMessage(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

TrustSMTPMessage::TrustSMTPMessage(const TrustSMTPMessage& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

TrustSMTPMessage::~TrustSMTPMessage()
{
}

TrustSMTPMessage& TrustSMTPMessage::operator=(const TrustSMTPMessage& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void TrustSMTPMessage::copy(const TrustSMTPMessage& other)
{
    this->from = other.from;
    this->to = other.to;
    this->msgId = other.msgId;
    this->sizeBytes = other.sizeBytes;
    this->trustScore = other.trustScore;
    this->isHandshake_ = other.isHandshake_;
    this->isData_ = other.isData_;
}

void TrustSMTPMessage::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->from);
    doParsimPacking(b,this->to);
    doParsimPacking(b,this->msgId);
    doParsimPacking(b,this->sizeBytes);
    doParsimPacking(b,this->trustScore);
    doParsimPacking(b,this->isHandshake_);
    doParsimPacking(b,this->isData_);
}

void TrustSMTPMessage::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->from);
    doParsimUnpacking(b,this->to);
    doParsimUnpacking(b,this->msgId);
    doParsimUnpacking(b,this->sizeBytes);
    doParsimUnpacking(b,this->trustScore);
    doParsimUnpacking(b,this->isHandshake_);
    doParsimUnpacking(b,this->isData_);
}

const char * TrustSMTPMessage::getFrom() const
{
    return this->from.c_str();
}

void TrustSMTPMessage::setFrom(const char * from)
{
    this->from = from;
}

const char * TrustSMTPMessage::getTo() const
{
    return this->to.c_str();
}

void TrustSMTPMessage::setTo(const char * to)
{
    this->to = to;
}

int TrustSMTPMessage::getMsgId() const
{
    return this->msgId;
}

void TrustSMTPMessage::setMsgId(int msgId)
{
    this->msgId = msgId;
}

int TrustSMTPMessage::getSizeBytes() const
{
    return this->sizeBytes;
}

void TrustSMTPMessage::setSizeBytes(int sizeBytes)
{
    this->sizeBytes = sizeBytes;
}

double TrustSMTPMessage::getTrustScore() const
{
    return this->trustScore;
}

void TrustSMTPMessage::setTrustScore(double trustScore)
{
    this->trustScore = trustScore;
}

bool TrustSMTPMessage::isHandshake() const
{
    return this->isHandshake_;
}

void TrustSMTPMessage::setIsHandshake(bool isHandshake)
{
    this->isHandshake_ = isHandshake;
}

bool TrustSMTPMessage::isData() const
{
    return this->isData_;
}

void TrustSMTPMessage::setIsData(bool isData)
{
    this->isData_ = isData;
}

class TrustSMTPMessageDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_from,
        FIELD_to,
        FIELD_msgId,
        FIELD_sizeBytes,
        FIELD_trustScore,
        FIELD_isHandshake,
        FIELD_isData,
    };
  public:
    TrustSMTPMessageDescriptor();
    virtual ~TrustSMTPMessageDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(TrustSMTPMessageDescriptor)

TrustSMTPMessageDescriptor::TrustSMTPMessageDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(peyal::TrustSMTPMessage)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

TrustSMTPMessageDescriptor::~TrustSMTPMessageDescriptor()
{
    delete[] propertyNames;
}

bool TrustSMTPMessageDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<TrustSMTPMessage *>(obj)!=nullptr;
}

const char **TrustSMTPMessageDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *TrustSMTPMessageDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int TrustSMTPMessageDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 7+base->getFieldCount() : 7;
}

unsigned int TrustSMTPMessageDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_from
        FD_ISEDITABLE,    // FIELD_to
        FD_ISEDITABLE,    // FIELD_msgId
        FD_ISEDITABLE,    // FIELD_sizeBytes
        FD_ISEDITABLE,    // FIELD_trustScore
        FD_ISEDITABLE,    // FIELD_isHandshake
        FD_ISEDITABLE,    // FIELD_isData
    };
    return (field >= 0 && field < 7) ? fieldTypeFlags[field] : 0;
}

const char *TrustSMTPMessageDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "from",
        "to",
        "msgId",
        "sizeBytes",
        "trustScore",
        "isHandshake",
        "isData",
    };
    return (field >= 0 && field < 7) ? fieldNames[field] : nullptr;
}

int TrustSMTPMessageDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "from") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "to") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "msgId") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "sizeBytes") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "trustScore") == 0) return baseIndex + 4;
    if (strcmp(fieldName, "isHandshake") == 0) return baseIndex + 5;
    if (strcmp(fieldName, "isData") == 0) return baseIndex + 6;
    return base ? base->findField(fieldName) : -1;
}

const char *TrustSMTPMessageDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "string",    // FIELD_from
        "string",    // FIELD_to
        "int",    // FIELD_msgId
        "int",    // FIELD_sizeBytes
        "double",    // FIELD_trustScore
        "bool",    // FIELD_isHandshake
        "bool",    // FIELD_isData
    };
    return (field >= 0 && field < 7) ? fieldTypeStrings[field] : nullptr;
}

const char **TrustSMTPMessageDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *TrustSMTPMessageDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int TrustSMTPMessageDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    TrustSMTPMessage *pp = omnetpp::fromAnyPtr<TrustSMTPMessage>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void TrustSMTPMessageDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    TrustSMTPMessage *pp = omnetpp::fromAnyPtr<TrustSMTPMessage>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'TrustSMTPMessage'", field);
    }
}

const char *TrustSMTPMessageDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    TrustSMTPMessage *pp = omnetpp::fromAnyPtr<TrustSMTPMessage>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string TrustSMTPMessageDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    TrustSMTPMessage *pp = omnetpp::fromAnyPtr<TrustSMTPMessage>(object); (void)pp;
    switch (field) {
        case FIELD_from: return oppstring2string(pp->getFrom());
        case FIELD_to: return oppstring2string(pp->getTo());
        case FIELD_msgId: return long2string(pp->getMsgId());
        case FIELD_sizeBytes: return long2string(pp->getSizeBytes());
        case FIELD_trustScore: return double2string(pp->getTrustScore());
        case FIELD_isHandshake: return bool2string(pp->isHandshake());
        case FIELD_isData: return bool2string(pp->isData());
        default: return "";
    }
}

void TrustSMTPMessageDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    TrustSMTPMessage *pp = omnetpp::fromAnyPtr<TrustSMTPMessage>(object); (void)pp;
    switch (field) {
        case FIELD_from: pp->setFrom((value)); break;
        case FIELD_to: pp->setTo((value)); break;
        case FIELD_msgId: pp->setMsgId(string2long(value)); break;
        case FIELD_sizeBytes: pp->setSizeBytes(string2long(value)); break;
        case FIELD_trustScore: pp->setTrustScore(string2double(value)); break;
        case FIELD_isHandshake: pp->setIsHandshake(string2bool(value)); break;
        case FIELD_isData: pp->setIsData(string2bool(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'TrustSMTPMessage'", field);
    }
}

omnetpp::cValue TrustSMTPMessageDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    TrustSMTPMessage *pp = omnetpp::fromAnyPtr<TrustSMTPMessage>(object); (void)pp;
    switch (field) {
        case FIELD_from: return pp->getFrom();
        case FIELD_to: return pp->getTo();
        case FIELD_msgId: return pp->getMsgId();
        case FIELD_sizeBytes: return pp->getSizeBytes();
        case FIELD_trustScore: return pp->getTrustScore();
        case FIELD_isHandshake: return pp->isHandshake();
        case FIELD_isData: return pp->isData();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'TrustSMTPMessage' as cValue -- field index out of range?", field);
    }
}

void TrustSMTPMessageDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    TrustSMTPMessage *pp = omnetpp::fromAnyPtr<TrustSMTPMessage>(object); (void)pp;
    switch (field) {
        case FIELD_from: pp->setFrom(value.stringValue()); break;
        case FIELD_to: pp->setTo(value.stringValue()); break;
        case FIELD_msgId: pp->setMsgId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_sizeBytes: pp->setSizeBytes(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_trustScore: pp->setTrustScore(value.doubleValue()); break;
        case FIELD_isHandshake: pp->setIsHandshake(value.boolValue()); break;
        case FIELD_isData: pp->setIsData(value.boolValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'TrustSMTPMessage'", field);
    }
}

const char *TrustSMTPMessageDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr TrustSMTPMessageDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    TrustSMTPMessage *pp = omnetpp::fromAnyPtr<TrustSMTPMessage>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void TrustSMTPMessageDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    TrustSMTPMessage *pp = omnetpp::fromAnyPtr<TrustSMTPMessage>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'TrustSMTPMessage'", field);
    }
}

Register_Class(SMTPCommand)

SMTPCommand::SMTPCommand(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

SMTPCommand::SMTPCommand(const SMTPCommand& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

SMTPCommand::~SMTPCommand()
{
}

SMTPCommand& SMTPCommand::operator=(const SMTPCommand& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void SMTPCommand::copy(const SMTPCommand& other)
{
    this->command = other.command;
    this->parameter = other.parameter;
    this->clientId = other.clientId;
    this->trustScore = other.trustScore;
}

void SMTPCommand::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->command);
    doParsimPacking(b,this->parameter);
    doParsimPacking(b,this->clientId);
    doParsimPacking(b,this->trustScore);
}

void SMTPCommand::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->command);
    doParsimUnpacking(b,this->parameter);
    doParsimUnpacking(b,this->clientId);
    doParsimUnpacking(b,this->trustScore);
}

const char * SMTPCommand::getCommand() const
{
    return this->command.c_str();
}

void SMTPCommand::setCommand(const char * command)
{
    this->command = command;
}

const char * SMTPCommand::getParameter() const
{
    return this->parameter.c_str();
}

void SMTPCommand::setParameter(const char * parameter)
{
    this->parameter = parameter;
}

const char * SMTPCommand::getClientId() const
{
    return this->clientId.c_str();
}

void SMTPCommand::setClientId(const char * clientId)
{
    this->clientId = clientId;
}

double SMTPCommand::getTrustScore() const
{
    return this->trustScore;
}

void SMTPCommand::setTrustScore(double trustScore)
{
    this->trustScore = trustScore;
}

class SMTPCommandDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_command,
        FIELD_parameter,
        FIELD_clientId,
        FIELD_trustScore,
    };
  public:
    SMTPCommandDescriptor();
    virtual ~SMTPCommandDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(SMTPCommandDescriptor)

SMTPCommandDescriptor::SMTPCommandDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(peyal::SMTPCommand)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

SMTPCommandDescriptor::~SMTPCommandDescriptor()
{
    delete[] propertyNames;
}

bool SMTPCommandDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SMTPCommand *>(obj)!=nullptr;
}

const char **SMTPCommandDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *SMTPCommandDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int SMTPCommandDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 4+base->getFieldCount() : 4;
}

unsigned int SMTPCommandDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_command
        FD_ISEDITABLE,    // FIELD_parameter
        FD_ISEDITABLE,    // FIELD_clientId
        FD_ISEDITABLE,    // FIELD_trustScore
    };
    return (field >= 0 && field < 4) ? fieldTypeFlags[field] : 0;
}

const char *SMTPCommandDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "command",
        "parameter",
        "clientId",
        "trustScore",
    };
    return (field >= 0 && field < 4) ? fieldNames[field] : nullptr;
}

int SMTPCommandDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "command") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "parameter") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "clientId") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "trustScore") == 0) return baseIndex + 3;
    return base ? base->findField(fieldName) : -1;
}

const char *SMTPCommandDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "string",    // FIELD_command
        "string",    // FIELD_parameter
        "string",    // FIELD_clientId
        "double",    // FIELD_trustScore
    };
    return (field >= 0 && field < 4) ? fieldTypeStrings[field] : nullptr;
}

const char **SMTPCommandDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *SMTPCommandDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int SMTPCommandDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    SMTPCommand *pp = omnetpp::fromAnyPtr<SMTPCommand>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void SMTPCommandDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    SMTPCommand *pp = omnetpp::fromAnyPtr<SMTPCommand>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'SMTPCommand'", field);
    }
}

const char *SMTPCommandDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    SMTPCommand *pp = omnetpp::fromAnyPtr<SMTPCommand>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SMTPCommandDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    SMTPCommand *pp = omnetpp::fromAnyPtr<SMTPCommand>(object); (void)pp;
    switch (field) {
        case FIELD_command: return oppstring2string(pp->getCommand());
        case FIELD_parameter: return oppstring2string(pp->getParameter());
        case FIELD_clientId: return oppstring2string(pp->getClientId());
        case FIELD_trustScore: return double2string(pp->getTrustScore());
        default: return "";
    }
}

void SMTPCommandDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    SMTPCommand *pp = omnetpp::fromAnyPtr<SMTPCommand>(object); (void)pp;
    switch (field) {
        case FIELD_command: pp->setCommand((value)); break;
        case FIELD_parameter: pp->setParameter((value)); break;
        case FIELD_clientId: pp->setClientId((value)); break;
        case FIELD_trustScore: pp->setTrustScore(string2double(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'SMTPCommand'", field);
    }
}

omnetpp::cValue SMTPCommandDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    SMTPCommand *pp = omnetpp::fromAnyPtr<SMTPCommand>(object); (void)pp;
    switch (field) {
        case FIELD_command: return pp->getCommand();
        case FIELD_parameter: return pp->getParameter();
        case FIELD_clientId: return pp->getClientId();
        case FIELD_trustScore: return pp->getTrustScore();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'SMTPCommand' as cValue -- field index out of range?", field);
    }
}

void SMTPCommandDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    SMTPCommand *pp = omnetpp::fromAnyPtr<SMTPCommand>(object); (void)pp;
    switch (field) {
        case FIELD_command: pp->setCommand(value.stringValue()); break;
        case FIELD_parameter: pp->setParameter(value.stringValue()); break;
        case FIELD_clientId: pp->setClientId(value.stringValue()); break;
        case FIELD_trustScore: pp->setTrustScore(value.doubleValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'SMTPCommand'", field);
    }
}

const char *SMTPCommandDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr SMTPCommandDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    SMTPCommand *pp = omnetpp::fromAnyPtr<SMTPCommand>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void SMTPCommandDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    SMTPCommand *pp = omnetpp::fromAnyPtr<SMTPCommand>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'SMTPCommand'", field);
    }
}

Register_Class(SMTPResponse)

SMTPResponse::SMTPResponse(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

SMTPResponse::SMTPResponse(const SMTPResponse& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

SMTPResponse::~SMTPResponse()
{
}

SMTPResponse& SMTPResponse::operator=(const SMTPResponse& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void SMTPResponse::copy(const SMTPResponse& other)
{
    this->code = other.code;
    this->statusText = other.statusText;
    this->success = other.success;
}

void SMTPResponse::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->code);
    doParsimPacking(b,this->statusText);
    doParsimPacking(b,this->success);
}

void SMTPResponse::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->code);
    doParsimUnpacking(b,this->statusText);
    doParsimUnpacking(b,this->success);
}

int SMTPResponse::getCode() const
{
    return this->code;
}

void SMTPResponse::setCode(int code)
{
    this->code = code;
}

const char * SMTPResponse::getStatusText() const
{
    return this->statusText.c_str();
}

void SMTPResponse::setStatusText(const char * statusText)
{
    this->statusText = statusText;
}

bool SMTPResponse::getSuccess() const
{
    return this->success;
}

void SMTPResponse::setSuccess(bool success)
{
    this->success = success;
}

class SMTPResponseDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_code,
        FIELD_statusText,
        FIELD_success,
    };
  public:
    SMTPResponseDescriptor();
    virtual ~SMTPResponseDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(SMTPResponseDescriptor)

SMTPResponseDescriptor::SMTPResponseDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(peyal::SMTPResponse)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

SMTPResponseDescriptor::~SMTPResponseDescriptor()
{
    delete[] propertyNames;
}

bool SMTPResponseDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SMTPResponse *>(obj)!=nullptr;
}

const char **SMTPResponseDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *SMTPResponseDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int SMTPResponseDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 3+base->getFieldCount() : 3;
}

unsigned int SMTPResponseDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_code
        FD_ISEDITABLE,    // FIELD_statusText
        FD_ISEDITABLE,    // FIELD_success
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *SMTPResponseDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "code",
        "statusText",
        "success",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int SMTPResponseDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "code") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "statusText") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "success") == 0) return baseIndex + 2;
    return base ? base->findField(fieldName) : -1;
}

const char *SMTPResponseDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_code
        "string",    // FIELD_statusText
        "bool",    // FIELD_success
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **SMTPResponseDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *SMTPResponseDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int SMTPResponseDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    SMTPResponse *pp = omnetpp::fromAnyPtr<SMTPResponse>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void SMTPResponseDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    SMTPResponse *pp = omnetpp::fromAnyPtr<SMTPResponse>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'SMTPResponse'", field);
    }
}

const char *SMTPResponseDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    SMTPResponse *pp = omnetpp::fromAnyPtr<SMTPResponse>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SMTPResponseDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    SMTPResponse *pp = omnetpp::fromAnyPtr<SMTPResponse>(object); (void)pp;
    switch (field) {
        case FIELD_code: return long2string(pp->getCode());
        case FIELD_statusText: return oppstring2string(pp->getStatusText());
        case FIELD_success: return bool2string(pp->getSuccess());
        default: return "";
    }
}

void SMTPResponseDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    SMTPResponse *pp = omnetpp::fromAnyPtr<SMTPResponse>(object); (void)pp;
    switch (field) {
        case FIELD_code: pp->setCode(string2long(value)); break;
        case FIELD_statusText: pp->setStatusText((value)); break;
        case FIELD_success: pp->setSuccess(string2bool(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'SMTPResponse'", field);
    }
}

omnetpp::cValue SMTPResponseDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    SMTPResponse *pp = omnetpp::fromAnyPtr<SMTPResponse>(object); (void)pp;
    switch (field) {
        case FIELD_code: return pp->getCode();
        case FIELD_statusText: return pp->getStatusText();
        case FIELD_success: return pp->getSuccess();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'SMTPResponse' as cValue -- field index out of range?", field);
    }
}

void SMTPResponseDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    SMTPResponse *pp = omnetpp::fromAnyPtr<SMTPResponse>(object); (void)pp;
    switch (field) {
        case FIELD_code: pp->setCode(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_statusText: pp->setStatusText(value.stringValue()); break;
        case FIELD_success: pp->setSuccess(value.boolValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'SMTPResponse'", field);
    }
}

const char *SMTPResponseDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr SMTPResponseDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    SMTPResponse *pp = omnetpp::fromAnyPtr<SMTPResponse>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void SMTPResponseDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    SMTPResponse *pp = omnetpp::fromAnyPtr<SMTPResponse>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'SMTPResponse'", field);
    }
}

Register_Class(SMTPData)

SMTPData::SMTPData(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

SMTPData::SMTPData(const SMTPData& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

SMTPData::~SMTPData()
{
}

SMTPData& SMTPData::operator=(const SMTPData& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void SMTPData::copy(const SMTPData& other)
{
    this->from = other.from;
    this->to = other.to;
    this->subject = other.subject;
    this->body = other.body;
    this->sizeBytes = other.sizeBytes;
    this->trustScore = other.trustScore;
    this->msgId = other.msgId;
}

void SMTPData::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->from);
    doParsimPacking(b,this->to);
    doParsimPacking(b,this->subject);
    doParsimPacking(b,this->body);
    doParsimPacking(b,this->sizeBytes);
    doParsimPacking(b,this->trustScore);
    doParsimPacking(b,this->msgId);
}

void SMTPData::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->from);
    doParsimUnpacking(b,this->to);
    doParsimUnpacking(b,this->subject);
    doParsimUnpacking(b,this->body);
    doParsimUnpacking(b,this->sizeBytes);
    doParsimUnpacking(b,this->trustScore);
    doParsimUnpacking(b,this->msgId);
}

const char * SMTPData::getFrom() const
{
    return this->from.c_str();
}

void SMTPData::setFrom(const char * from)
{
    this->from = from;
}

const char * SMTPData::getTo() const
{
    return this->to.c_str();
}

void SMTPData::setTo(const char * to)
{
    this->to = to;
}

const char * SMTPData::getSubject() const
{
    return this->subject.c_str();
}

void SMTPData::setSubject(const char * subject)
{
    this->subject = subject;
}

const char * SMTPData::getBody() const
{
    return this->body.c_str();
}

void SMTPData::setBody(const char * body)
{
    this->body = body;
}

int SMTPData::getSizeBytes() const
{
    return this->sizeBytes;
}

void SMTPData::setSizeBytes(int sizeBytes)
{
    this->sizeBytes = sizeBytes;
}

double SMTPData::getTrustScore() const
{
    return this->trustScore;
}

void SMTPData::setTrustScore(double trustScore)
{
    this->trustScore = trustScore;
}

int SMTPData::getMsgId() const
{
    return this->msgId;
}

void SMTPData::setMsgId(int msgId)
{
    this->msgId = msgId;
}

class SMTPDataDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_from,
        FIELD_to,
        FIELD_subject,
        FIELD_body,
        FIELD_sizeBytes,
        FIELD_trustScore,
        FIELD_msgId,
    };
  public:
    SMTPDataDescriptor();
    virtual ~SMTPDataDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(SMTPDataDescriptor)

SMTPDataDescriptor::SMTPDataDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(peyal::SMTPData)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

SMTPDataDescriptor::~SMTPDataDescriptor()
{
    delete[] propertyNames;
}

bool SMTPDataDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SMTPData *>(obj)!=nullptr;
}

const char **SMTPDataDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *SMTPDataDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int SMTPDataDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 7+base->getFieldCount() : 7;
}

unsigned int SMTPDataDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_from
        FD_ISEDITABLE,    // FIELD_to
        FD_ISEDITABLE,    // FIELD_subject
        FD_ISEDITABLE,    // FIELD_body
        FD_ISEDITABLE,    // FIELD_sizeBytes
        FD_ISEDITABLE,    // FIELD_trustScore
        FD_ISEDITABLE,    // FIELD_msgId
    };
    return (field >= 0 && field < 7) ? fieldTypeFlags[field] : 0;
}

const char *SMTPDataDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "from",
        "to",
        "subject",
        "body",
        "sizeBytes",
        "trustScore",
        "msgId",
    };
    return (field >= 0 && field < 7) ? fieldNames[field] : nullptr;
}

int SMTPDataDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "from") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "to") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "subject") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "body") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "sizeBytes") == 0) return baseIndex + 4;
    if (strcmp(fieldName, "trustScore") == 0) return baseIndex + 5;
    if (strcmp(fieldName, "msgId") == 0) return baseIndex + 6;
    return base ? base->findField(fieldName) : -1;
}

const char *SMTPDataDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "string",    // FIELD_from
        "string",    // FIELD_to
        "string",    // FIELD_subject
        "string",    // FIELD_body
        "int",    // FIELD_sizeBytes
        "double",    // FIELD_trustScore
        "int",    // FIELD_msgId
    };
    return (field >= 0 && field < 7) ? fieldTypeStrings[field] : nullptr;
}

const char **SMTPDataDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *SMTPDataDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int SMTPDataDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    SMTPData *pp = omnetpp::fromAnyPtr<SMTPData>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void SMTPDataDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    SMTPData *pp = omnetpp::fromAnyPtr<SMTPData>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'SMTPData'", field);
    }
}

const char *SMTPDataDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    SMTPData *pp = omnetpp::fromAnyPtr<SMTPData>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SMTPDataDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    SMTPData *pp = omnetpp::fromAnyPtr<SMTPData>(object); (void)pp;
    switch (field) {
        case FIELD_from: return oppstring2string(pp->getFrom());
        case FIELD_to: return oppstring2string(pp->getTo());
        case FIELD_subject: return oppstring2string(pp->getSubject());
        case FIELD_body: return oppstring2string(pp->getBody());
        case FIELD_sizeBytes: return long2string(pp->getSizeBytes());
        case FIELD_trustScore: return double2string(pp->getTrustScore());
        case FIELD_msgId: return long2string(pp->getMsgId());
        default: return "";
    }
}

void SMTPDataDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    SMTPData *pp = omnetpp::fromAnyPtr<SMTPData>(object); (void)pp;
    switch (field) {
        case FIELD_from: pp->setFrom((value)); break;
        case FIELD_to: pp->setTo((value)); break;
        case FIELD_subject: pp->setSubject((value)); break;
        case FIELD_body: pp->setBody((value)); break;
        case FIELD_sizeBytes: pp->setSizeBytes(string2long(value)); break;
        case FIELD_trustScore: pp->setTrustScore(string2double(value)); break;
        case FIELD_msgId: pp->setMsgId(string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'SMTPData'", field);
    }
}

omnetpp::cValue SMTPDataDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    SMTPData *pp = omnetpp::fromAnyPtr<SMTPData>(object); (void)pp;
    switch (field) {
        case FIELD_from: return pp->getFrom();
        case FIELD_to: return pp->getTo();
        case FIELD_subject: return pp->getSubject();
        case FIELD_body: return pp->getBody();
        case FIELD_sizeBytes: return pp->getSizeBytes();
        case FIELD_trustScore: return pp->getTrustScore();
        case FIELD_msgId: return pp->getMsgId();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'SMTPData' as cValue -- field index out of range?", field);
    }
}

void SMTPDataDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    SMTPData *pp = omnetpp::fromAnyPtr<SMTPData>(object); (void)pp;
    switch (field) {
        case FIELD_from: pp->setFrom(value.stringValue()); break;
        case FIELD_to: pp->setTo(value.stringValue()); break;
        case FIELD_subject: pp->setSubject(value.stringValue()); break;
        case FIELD_body: pp->setBody(value.stringValue()); break;
        case FIELD_sizeBytes: pp->setSizeBytes(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_trustScore: pp->setTrustScore(value.doubleValue()); break;
        case FIELD_msgId: pp->setMsgId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'SMTPData'", field);
    }
}

const char *SMTPDataDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr SMTPDataDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    SMTPData *pp = omnetpp::fromAnyPtr<SMTPData>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void SMTPDataDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    SMTPData *pp = omnetpp::fromAnyPtr<SMTPData>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'SMTPData'", field);
    }
}

Register_Class(TrustQueryMsg)

TrustQueryMsg::TrustQueryMsg(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

TrustQueryMsg::TrustQueryMsg(const TrustQueryMsg& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

TrustQueryMsg::~TrustQueryMsg()
{
}

TrustQueryMsg& TrustQueryMsg::operator=(const TrustQueryMsg& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void TrustQueryMsg::copy(const TrustQueryMsg& other)
{
    this->sender = other.sender;
}

void TrustQueryMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->sender);
}

void TrustQueryMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->sender);
}

const char * TrustQueryMsg::getSender() const
{
    return this->sender.c_str();
}

void TrustQueryMsg::setSender(const char * sender)
{
    this->sender = sender;
}

class TrustQueryMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_sender,
    };
  public:
    TrustQueryMsgDescriptor();
    virtual ~TrustQueryMsgDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(TrustQueryMsgDescriptor)

TrustQueryMsgDescriptor::TrustQueryMsgDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(peyal::TrustQueryMsg)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

TrustQueryMsgDescriptor::~TrustQueryMsgDescriptor()
{
    delete[] propertyNames;
}

bool TrustQueryMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<TrustQueryMsg *>(obj)!=nullptr;
}

const char **TrustQueryMsgDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *TrustQueryMsgDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int TrustQueryMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 1+base->getFieldCount() : 1;
}

unsigned int TrustQueryMsgDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_sender
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *TrustQueryMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "sender",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int TrustQueryMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "sender") == 0) return baseIndex + 0;
    return base ? base->findField(fieldName) : -1;
}

const char *TrustQueryMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "string",    // FIELD_sender
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **TrustQueryMsgDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *TrustQueryMsgDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int TrustQueryMsgDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    TrustQueryMsg *pp = omnetpp::fromAnyPtr<TrustQueryMsg>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void TrustQueryMsgDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    TrustQueryMsg *pp = omnetpp::fromAnyPtr<TrustQueryMsg>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'TrustQueryMsg'", field);
    }
}

const char *TrustQueryMsgDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    TrustQueryMsg *pp = omnetpp::fromAnyPtr<TrustQueryMsg>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string TrustQueryMsgDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    TrustQueryMsg *pp = omnetpp::fromAnyPtr<TrustQueryMsg>(object); (void)pp;
    switch (field) {
        case FIELD_sender: return oppstring2string(pp->getSender());
        default: return "";
    }
}

void TrustQueryMsgDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    TrustQueryMsg *pp = omnetpp::fromAnyPtr<TrustQueryMsg>(object); (void)pp;
    switch (field) {
        case FIELD_sender: pp->setSender((value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'TrustQueryMsg'", field);
    }
}

omnetpp::cValue TrustQueryMsgDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    TrustQueryMsg *pp = omnetpp::fromAnyPtr<TrustQueryMsg>(object); (void)pp;
    switch (field) {
        case FIELD_sender: return pp->getSender();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'TrustQueryMsg' as cValue -- field index out of range?", field);
    }
}

void TrustQueryMsgDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    TrustQueryMsg *pp = omnetpp::fromAnyPtr<TrustQueryMsg>(object); (void)pp;
    switch (field) {
        case FIELD_sender: pp->setSender(value.stringValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'TrustQueryMsg'", field);
    }
}

const char *TrustQueryMsgDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr TrustQueryMsgDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    TrustQueryMsg *pp = omnetpp::fromAnyPtr<TrustQueryMsg>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void TrustQueryMsgDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    TrustQueryMsg *pp = omnetpp::fromAnyPtr<TrustQueryMsg>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'TrustQueryMsg'", field);
    }
}

Register_Class(TrustReplyMsg)

TrustReplyMsg::TrustReplyMsg(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

TrustReplyMsg::TrustReplyMsg(const TrustReplyMsg& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

TrustReplyMsg::~TrustReplyMsg()
{
}

TrustReplyMsg& TrustReplyMsg::operator=(const TrustReplyMsg& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void TrustReplyMsg::copy(const TrustReplyMsg& other)
{
    this->sender = other.sender;
    this->score = other.score;
}

void TrustReplyMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->sender);
    doParsimPacking(b,this->score);
}

void TrustReplyMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->sender);
    doParsimUnpacking(b,this->score);
}

const char * TrustReplyMsg::getSender() const
{
    return this->sender.c_str();
}

void TrustReplyMsg::setSender(const char * sender)
{
    this->sender = sender;
}

double TrustReplyMsg::getScore() const
{
    return this->score;
}

void TrustReplyMsg::setScore(double score)
{
    this->score = score;
}

class TrustReplyMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_sender,
        FIELD_score,
    };
  public:
    TrustReplyMsgDescriptor();
    virtual ~TrustReplyMsgDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(TrustReplyMsgDescriptor)

TrustReplyMsgDescriptor::TrustReplyMsgDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(peyal::TrustReplyMsg)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

TrustReplyMsgDescriptor::~TrustReplyMsgDescriptor()
{
    delete[] propertyNames;
}

bool TrustReplyMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<TrustReplyMsg *>(obj)!=nullptr;
}

const char **TrustReplyMsgDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *TrustReplyMsgDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int TrustReplyMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 2+base->getFieldCount() : 2;
}

unsigned int TrustReplyMsgDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_sender
        FD_ISEDITABLE,    // FIELD_score
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *TrustReplyMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "sender",
        "score",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int TrustReplyMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "sender") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "score") == 0) return baseIndex + 1;
    return base ? base->findField(fieldName) : -1;
}

const char *TrustReplyMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "string",    // FIELD_sender
        "double",    // FIELD_score
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **TrustReplyMsgDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *TrustReplyMsgDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int TrustReplyMsgDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    TrustReplyMsg *pp = omnetpp::fromAnyPtr<TrustReplyMsg>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void TrustReplyMsgDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    TrustReplyMsg *pp = omnetpp::fromAnyPtr<TrustReplyMsg>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'TrustReplyMsg'", field);
    }
}

const char *TrustReplyMsgDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    TrustReplyMsg *pp = omnetpp::fromAnyPtr<TrustReplyMsg>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string TrustReplyMsgDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    TrustReplyMsg *pp = omnetpp::fromAnyPtr<TrustReplyMsg>(object); (void)pp;
    switch (field) {
        case FIELD_sender: return oppstring2string(pp->getSender());
        case FIELD_score: return double2string(pp->getScore());
        default: return "";
    }
}

void TrustReplyMsgDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    TrustReplyMsg *pp = omnetpp::fromAnyPtr<TrustReplyMsg>(object); (void)pp;
    switch (field) {
        case FIELD_sender: pp->setSender((value)); break;
        case FIELD_score: pp->setScore(string2double(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'TrustReplyMsg'", field);
    }
}

omnetpp::cValue TrustReplyMsgDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    TrustReplyMsg *pp = omnetpp::fromAnyPtr<TrustReplyMsg>(object); (void)pp;
    switch (field) {
        case FIELD_sender: return pp->getSender();
        case FIELD_score: return pp->getScore();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'TrustReplyMsg' as cValue -- field index out of range?", field);
    }
}

void TrustReplyMsgDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    TrustReplyMsg *pp = omnetpp::fromAnyPtr<TrustReplyMsg>(object); (void)pp;
    switch (field) {
        case FIELD_sender: pp->setSender(value.stringValue()); break;
        case FIELD_score: pp->setScore(value.doubleValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'TrustReplyMsg'", field);
    }
}

const char *TrustReplyMsgDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr TrustReplyMsgDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    TrustReplyMsg *pp = omnetpp::fromAnyPtr<TrustReplyMsg>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void TrustReplyMsgDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    TrustReplyMsg *pp = omnetpp::fromAnyPtr<TrustReplyMsg>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'TrustReplyMsg'", field);
    }
}

}  // namespace peyal

namespace omnetpp {

}  // namespace omnetpp

