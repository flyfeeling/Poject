// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Msg_AI.proto

#include "Msg_AI.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
class SvrRegToSvrReqDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<SvrRegToSvrReq>
      _instance;
} _SvrRegToSvrReq_default_instance_;
class SvrRegToSvrAckDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<SvrRegToSvrAck>
      _instance;
} _SvrRegToSvrAck_default_instance_;
namespace protobuf_Msg_5fAI_2eproto {
void InitDefaultsSvrRegToSvrReqImpl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::internal::InitProtobufDefaults();
  {
    void* ptr = &::_SvrRegToSvrReq_default_instance_;
    new (ptr) ::SvrRegToSvrReq();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::SvrRegToSvrReq::InitAsDefaultInstance();
}

void InitDefaultsSvrRegToSvrReq() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &InitDefaultsSvrRegToSvrReqImpl);
}

void InitDefaultsSvrRegToSvrAckImpl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::internal::InitProtobufDefaults();
  {
    void* ptr = &::_SvrRegToSvrAck_default_instance_;
    new (ptr) ::SvrRegToSvrAck();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::SvrRegToSvrAck::InitAsDefaultInstance();
}

void InitDefaultsSvrRegToSvrAck() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &InitDefaultsSvrRegToSvrAckImpl);
}

::google::protobuf::Metadata file_level_metadata[2];

const ::google::protobuf::uint32 TableStruct::offsets[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::SvrRegToSvrReq, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::SvrRegToSvrReq, serverid_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::SvrRegToSvrReq, servername_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::SvrRegToSvrReq, serverip_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::SvrRegToSvrReq, serverport_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::SvrRegToSvrReq, httpport_),
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::SvrRegToSvrAck, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::SvrRegToSvrAck, retcode_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::SvrRegToSvrAck, newsvrname_),
};
static const ::google::protobuf::internal::MigrationSchema schemas[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::SvrRegToSvrReq)},
  { 10, -1, sizeof(::SvrRegToSvrAck)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&::_SvrRegToSvrReq_default_instance_),
  reinterpret_cast<const ::google::protobuf::Message*>(&::_SvrRegToSvrAck_default_instance_),
};

void protobuf_AssignDescriptors() {
  AddDescriptors();
  ::google::protobuf::MessageFactory* factory = NULL;
  AssignDescriptors(
      "Msg_AI.proto", schemas, file_default_instances, TableStruct::offsets, factory,
      file_level_metadata, NULL, NULL);
}

void protobuf_AssignDescriptorsOnce() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &protobuf_AssignDescriptors);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_PROTOBUF_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::internal::RegisterAllTypes(file_level_metadata, 2);
}

void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
      "\n\014Msg_AI.proto\"n\n\016SvrRegToSvrReq\022\020\n\010Serv"
      "erID\030\001 \001(\005\022\022\n\nServerName\030\002 \001(\t\022\020\n\010Server"
      "Ip\030\003 \001(\t\022\022\n\nServerPort\030\004 \001(\005\022\020\n\010HttpPort"
      "\030\005 \001(\005\"5\n\016SvrRegToSvrAck\022\017\n\007RetCode\030\001 \001("
      "\005\022\022\n\nNewSvrName\030\002 \001(\tb\006proto3"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 189);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "Msg_AI.proto", &protobuf_RegisterTypes);
}

void AddDescriptors() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &AddDescriptorsImpl);
}
// Force AddDescriptors() to be called at dynamic initialization time.
struct StaticDescriptorInitializer {
  StaticDescriptorInitializer() {
    AddDescriptors();
  }
} static_descriptor_initializer;
}  // namespace protobuf_Msg_5fAI_2eproto

// ===================================================================

void SvrRegToSvrReq::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int SvrRegToSvrReq::kServerIDFieldNumber;
const int SvrRegToSvrReq::kServerNameFieldNumber;
const int SvrRegToSvrReq::kServerIpFieldNumber;
const int SvrRegToSvrReq::kServerPortFieldNumber;
const int SvrRegToSvrReq::kHttpPortFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

SvrRegToSvrReq::SvrRegToSvrReq()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  if (GOOGLE_PREDICT_TRUE(this != internal_default_instance())) {
    ::protobuf_Msg_5fAI_2eproto::InitDefaultsSvrRegToSvrReq();
  }
  SharedCtor();
  // @@protoc_insertion_point(constructor:SvrRegToSvrReq)
}
SvrRegToSvrReq::SvrRegToSvrReq(const SvrRegToSvrReq& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      _cached_size_(0) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  servername_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.servername().size() > 0) {
    servername_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.servername_);
  }
  serverip_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.serverip().size() > 0) {
    serverip_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.serverip_);
  }
  ::memcpy(&serverid_, &from.serverid_,
    static_cast<size_t>(reinterpret_cast<char*>(&httpport_) -
    reinterpret_cast<char*>(&serverid_)) + sizeof(httpport_));
  // @@protoc_insertion_point(copy_constructor:SvrRegToSvrReq)
}

void SvrRegToSvrReq::SharedCtor() {
  servername_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  serverip_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(&serverid_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&httpport_) -
      reinterpret_cast<char*>(&serverid_)) + sizeof(httpport_));
  _cached_size_ = 0;
}

SvrRegToSvrReq::~SvrRegToSvrReq() {
  // @@protoc_insertion_point(destructor:SvrRegToSvrReq)
  SharedDtor();
}

void SvrRegToSvrReq::SharedDtor() {
  servername_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  serverip_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

void SvrRegToSvrReq::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* SvrRegToSvrReq::descriptor() {
  ::protobuf_Msg_5fAI_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_Msg_5fAI_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const SvrRegToSvrReq& SvrRegToSvrReq::default_instance() {
  ::protobuf_Msg_5fAI_2eproto::InitDefaultsSvrRegToSvrReq();
  return *internal_default_instance();
}

SvrRegToSvrReq* SvrRegToSvrReq::New(::google::protobuf::Arena* arena) const {
  SvrRegToSvrReq* n = new SvrRegToSvrReq;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void SvrRegToSvrReq::Clear() {
// @@protoc_insertion_point(message_clear_start:SvrRegToSvrReq)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  servername_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  serverip_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(&serverid_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&httpport_) -
      reinterpret_cast<char*>(&serverid_)) + sizeof(httpport_));
  _internal_metadata_.Clear();
}

bool SvrRegToSvrReq::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:SvrRegToSvrReq)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // int32 ServerID = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(8u /* 8 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &serverid_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // string ServerName = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(18u /* 18 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_servername()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->servername().data(), static_cast<int>(this->servername().length()),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "SvrRegToSvrReq.ServerName"));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // string ServerIp = 3;
      case 3: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(26u /* 26 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_serverip()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->serverip().data(), static_cast<int>(this->serverip().length()),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "SvrRegToSvrReq.ServerIp"));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // int32 ServerPort = 4;
      case 4: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(32u /* 32 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &serverport_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // int32 HttpPort = 5;
      case 5: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(40u /* 40 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &httpport_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:SvrRegToSvrReq)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:SvrRegToSvrReq)
  return false;
#undef DO_
}

void SvrRegToSvrReq::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:SvrRegToSvrReq)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // int32 ServerID = 1;
  if (this->serverid() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->serverid(), output);
  }

  // string ServerName = 2;
  if (this->servername().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->servername().data(), static_cast<int>(this->servername().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "SvrRegToSvrReq.ServerName");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      2, this->servername(), output);
  }

  // string ServerIp = 3;
  if (this->serverip().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->serverip().data(), static_cast<int>(this->serverip().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "SvrRegToSvrReq.ServerIp");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      3, this->serverip(), output);
  }

  // int32 ServerPort = 4;
  if (this->serverport() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(4, this->serverport(), output);
  }

  // int32 HttpPort = 5;
  if (this->httpport() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(5, this->httpport(), output);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), output);
  }
  // @@protoc_insertion_point(serialize_end:SvrRegToSvrReq)
}

::google::protobuf::uint8* SvrRegToSvrReq::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:SvrRegToSvrReq)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // int32 ServerID = 1;
  if (this->serverid() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, this->serverid(), target);
  }

  // string ServerName = 2;
  if (this->servername().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->servername().data(), static_cast<int>(this->servername().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "SvrRegToSvrReq.ServerName");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->servername(), target);
  }

  // string ServerIp = 3;
  if (this->serverip().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->serverip().data(), static_cast<int>(this->serverip().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "SvrRegToSvrReq.ServerIp");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        3, this->serverip(), target);
  }

  // int32 ServerPort = 4;
  if (this->serverport() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(4, this->serverport(), target);
  }

  // int32 HttpPort = 5;
  if (this->httpport() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(5, this->httpport(), target);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:SvrRegToSvrReq)
  return target;
}

size_t SvrRegToSvrReq::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:SvrRegToSvrReq)
  size_t total_size = 0;

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()));
  }
  // string ServerName = 2;
  if (this->servername().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->servername());
  }

  // string ServerIp = 3;
  if (this->serverip().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->serverip());
  }

  // int32 ServerID = 1;
  if (this->serverid() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->serverid());
  }

  // int32 ServerPort = 4;
  if (this->serverport() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->serverport());
  }

  // int32 HttpPort = 5;
  if (this->httpport() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->httpport());
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void SvrRegToSvrReq::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:SvrRegToSvrReq)
  GOOGLE_DCHECK_NE(&from, this);
  const SvrRegToSvrReq* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const SvrRegToSvrReq>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:SvrRegToSvrReq)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:SvrRegToSvrReq)
    MergeFrom(*source);
  }
}

void SvrRegToSvrReq::MergeFrom(const SvrRegToSvrReq& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:SvrRegToSvrReq)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.servername().size() > 0) {

    servername_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.servername_);
  }
  if (from.serverip().size() > 0) {

    serverip_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.serverip_);
  }
  if (from.serverid() != 0) {
    set_serverid(from.serverid());
  }
  if (from.serverport() != 0) {
    set_serverport(from.serverport());
  }
  if (from.httpport() != 0) {
    set_httpport(from.httpport());
  }
}

void SvrRegToSvrReq::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:SvrRegToSvrReq)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void SvrRegToSvrReq::CopyFrom(const SvrRegToSvrReq& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:SvrRegToSvrReq)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool SvrRegToSvrReq::IsInitialized() const {
  return true;
}

void SvrRegToSvrReq::Swap(SvrRegToSvrReq* other) {
  if (other == this) return;
  InternalSwap(other);
}
void SvrRegToSvrReq::InternalSwap(SvrRegToSvrReq* other) {
  using std::swap;
  servername_.Swap(&other->servername_);
  serverip_.Swap(&other->serverip_);
  swap(serverid_, other->serverid_);
  swap(serverport_, other->serverport_);
  swap(httpport_, other->httpport_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata SvrRegToSvrReq::GetMetadata() const {
  protobuf_Msg_5fAI_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_Msg_5fAI_2eproto::file_level_metadata[kIndexInFileMessages];
}


// ===================================================================

void SvrRegToSvrAck::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int SvrRegToSvrAck::kRetCodeFieldNumber;
const int SvrRegToSvrAck::kNewSvrNameFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

SvrRegToSvrAck::SvrRegToSvrAck()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  if (GOOGLE_PREDICT_TRUE(this != internal_default_instance())) {
    ::protobuf_Msg_5fAI_2eproto::InitDefaultsSvrRegToSvrAck();
  }
  SharedCtor();
  // @@protoc_insertion_point(constructor:SvrRegToSvrAck)
}
SvrRegToSvrAck::SvrRegToSvrAck(const SvrRegToSvrAck& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      _cached_size_(0) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  newsvrname_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.newsvrname().size() > 0) {
    newsvrname_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.newsvrname_);
  }
  retcode_ = from.retcode_;
  // @@protoc_insertion_point(copy_constructor:SvrRegToSvrAck)
}

void SvrRegToSvrAck::SharedCtor() {
  newsvrname_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  retcode_ = 0;
  _cached_size_ = 0;
}

SvrRegToSvrAck::~SvrRegToSvrAck() {
  // @@protoc_insertion_point(destructor:SvrRegToSvrAck)
  SharedDtor();
}

void SvrRegToSvrAck::SharedDtor() {
  newsvrname_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

void SvrRegToSvrAck::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* SvrRegToSvrAck::descriptor() {
  ::protobuf_Msg_5fAI_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_Msg_5fAI_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const SvrRegToSvrAck& SvrRegToSvrAck::default_instance() {
  ::protobuf_Msg_5fAI_2eproto::InitDefaultsSvrRegToSvrAck();
  return *internal_default_instance();
}

SvrRegToSvrAck* SvrRegToSvrAck::New(::google::protobuf::Arena* arena) const {
  SvrRegToSvrAck* n = new SvrRegToSvrAck;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void SvrRegToSvrAck::Clear() {
// @@protoc_insertion_point(message_clear_start:SvrRegToSvrAck)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  newsvrname_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  retcode_ = 0;
  _internal_metadata_.Clear();
}

bool SvrRegToSvrAck::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:SvrRegToSvrAck)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // int32 RetCode = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(8u /* 8 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &retcode_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // string NewSvrName = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(18u /* 18 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_newsvrname()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->newsvrname().data(), static_cast<int>(this->newsvrname().length()),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "SvrRegToSvrAck.NewSvrName"));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:SvrRegToSvrAck)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:SvrRegToSvrAck)
  return false;
#undef DO_
}

void SvrRegToSvrAck::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:SvrRegToSvrAck)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // int32 RetCode = 1;
  if (this->retcode() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->retcode(), output);
  }

  // string NewSvrName = 2;
  if (this->newsvrname().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->newsvrname().data(), static_cast<int>(this->newsvrname().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "SvrRegToSvrAck.NewSvrName");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      2, this->newsvrname(), output);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), output);
  }
  // @@protoc_insertion_point(serialize_end:SvrRegToSvrAck)
}

::google::protobuf::uint8* SvrRegToSvrAck::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:SvrRegToSvrAck)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // int32 RetCode = 1;
  if (this->retcode() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, this->retcode(), target);
  }

  // string NewSvrName = 2;
  if (this->newsvrname().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->newsvrname().data(), static_cast<int>(this->newsvrname().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "SvrRegToSvrAck.NewSvrName");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->newsvrname(), target);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:SvrRegToSvrAck)
  return target;
}

size_t SvrRegToSvrAck::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:SvrRegToSvrAck)
  size_t total_size = 0;

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()));
  }
  // string NewSvrName = 2;
  if (this->newsvrname().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->newsvrname());
  }

  // int32 RetCode = 1;
  if (this->retcode() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->retcode());
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void SvrRegToSvrAck::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:SvrRegToSvrAck)
  GOOGLE_DCHECK_NE(&from, this);
  const SvrRegToSvrAck* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const SvrRegToSvrAck>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:SvrRegToSvrAck)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:SvrRegToSvrAck)
    MergeFrom(*source);
  }
}

void SvrRegToSvrAck::MergeFrom(const SvrRegToSvrAck& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:SvrRegToSvrAck)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.newsvrname().size() > 0) {

    newsvrname_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.newsvrname_);
  }
  if (from.retcode() != 0) {
    set_retcode(from.retcode());
  }
}

void SvrRegToSvrAck::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:SvrRegToSvrAck)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void SvrRegToSvrAck::CopyFrom(const SvrRegToSvrAck& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:SvrRegToSvrAck)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool SvrRegToSvrAck::IsInitialized() const {
  return true;
}

void SvrRegToSvrAck::Swap(SvrRegToSvrAck* other) {
  if (other == this) return;
  InternalSwap(other);
}
void SvrRegToSvrAck::InternalSwap(SvrRegToSvrAck* other) {
  using std::swap;
  newsvrname_.Swap(&other->newsvrname_);
  swap(retcode_, other->retcode_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata SvrRegToSvrAck::GetMetadata() const {
  protobuf_Msg_5fAI_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_Msg_5fAI_2eproto::file_level_metadata[kIndexInFileMessages];
}


// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)
