// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: level.proto

#include "level.pb.h"

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
namespace protoMsg {
class MoraleInfoDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<MoraleInfo>
      _instance;
} _MoraleInfo_default_instance_;
class MoraleInfoListDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<MoraleInfoList>
      _instance;
} _MoraleInfoList_default_instance_;
}  // namespace protoMsg
namespace protobuf_level_2eproto {
void InitDefaultsMoraleInfoImpl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::internal::InitProtobufDefaults();
  {
    void* ptr = &::protoMsg::_MoraleInfo_default_instance_;
    new (ptr) ::protoMsg::MoraleInfo();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::protoMsg::MoraleInfo::InitAsDefaultInstance();
}

void InitDefaultsMoraleInfo() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &InitDefaultsMoraleInfoImpl);
}

void InitDefaultsMoraleInfoListImpl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::internal::InitProtobufDefaults();
  protobuf_level_2eproto::InitDefaultsMoraleInfo();
  {
    void* ptr = &::protoMsg::_MoraleInfoList_default_instance_;
    new (ptr) ::protoMsg::MoraleInfoList();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::protoMsg::MoraleInfoList::InitAsDefaultInstance();
}

void InitDefaultsMoraleInfoList() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &InitDefaultsMoraleInfoListImpl);
}

::google::protobuf::Metadata file_level_metadata[2];

const ::google::protobuf::uint32 TableStruct::offsets[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::protoMsg::MoraleInfo, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::protoMsg::MoraleInfo, camp_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::protoMsg::MoraleInfo, buffvalue_),
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::protoMsg::MoraleInfoList, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::protoMsg::MoraleInfoList, moraleinfo_),
};
static const ::google::protobuf::internal::MigrationSchema schemas[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::protoMsg::MoraleInfo)},
  { 7, -1, sizeof(::protoMsg::MoraleInfoList)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&::protoMsg::_MoraleInfo_default_instance_),
  reinterpret_cast<const ::google::protobuf::Message*>(&::protoMsg::_MoraleInfoList_default_instance_),
};

void protobuf_AssignDescriptors() {
  AddDescriptors();
  ::google::protobuf::MessageFactory* factory = NULL;
  AssignDescriptors(
      "level.proto", schemas, file_default_instances, TableStruct::offsets, factory,
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
      "\n\013level.proto\022\010protoMsg\"-\n\nMoraleInfo\022\014\n"
      "\004camp\030\001 \001(\005\022\021\n\tbuffvalue\030\002 \001(\005\":\n\016Morale"
      "InfoList\022(\n\nmoraleInfo\030\001 \003(\0132\024.protoMsg."
      "MoraleInfob\006proto3"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 138);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "level.proto", &protobuf_RegisterTypes);
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
}  // namespace protobuf_level_2eproto
namespace protoMsg {

// ===================================================================

void MoraleInfo::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int MoraleInfo::kCampFieldNumber;
const int MoraleInfo::kBuffvalueFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

MoraleInfo::MoraleInfo()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  if (GOOGLE_PREDICT_TRUE(this != internal_default_instance())) {
    ::protobuf_level_2eproto::InitDefaultsMoraleInfo();
  }
  SharedCtor();
  // @@protoc_insertion_point(constructor:protoMsg.MoraleInfo)
}
MoraleInfo::MoraleInfo(const MoraleInfo& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      _cached_size_(0) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::memcpy(&camp_, &from.camp_,
    static_cast<size_t>(reinterpret_cast<char*>(&buffvalue_) -
    reinterpret_cast<char*>(&camp_)) + sizeof(buffvalue_));
  // @@protoc_insertion_point(copy_constructor:protoMsg.MoraleInfo)
}

void MoraleInfo::SharedCtor() {
  ::memset(&camp_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&buffvalue_) -
      reinterpret_cast<char*>(&camp_)) + sizeof(buffvalue_));
  _cached_size_ = 0;
}

MoraleInfo::~MoraleInfo() {
  // @@protoc_insertion_point(destructor:protoMsg.MoraleInfo)
  SharedDtor();
}

void MoraleInfo::SharedDtor() {
}

void MoraleInfo::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* MoraleInfo::descriptor() {
  ::protobuf_level_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_level_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const MoraleInfo& MoraleInfo::default_instance() {
  ::protobuf_level_2eproto::InitDefaultsMoraleInfo();
  return *internal_default_instance();
}

MoraleInfo* MoraleInfo::New(::google::protobuf::Arena* arena) const {
  MoraleInfo* n = new MoraleInfo;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void MoraleInfo::Clear() {
// @@protoc_insertion_point(message_clear_start:protoMsg.MoraleInfo)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  ::memset(&camp_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&buffvalue_) -
      reinterpret_cast<char*>(&camp_)) + sizeof(buffvalue_));
  _internal_metadata_.Clear();
}

bool MoraleInfo::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:protoMsg.MoraleInfo)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // int32 camp = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(8u /* 8 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &camp_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // int32 buffvalue = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(16u /* 16 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &buffvalue_)));
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
  // @@protoc_insertion_point(parse_success:protoMsg.MoraleInfo)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:protoMsg.MoraleInfo)
  return false;
#undef DO_
}

void MoraleInfo::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:protoMsg.MoraleInfo)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // int32 camp = 1;
  if (this->camp() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->camp(), output);
  }

  // int32 buffvalue = 2;
  if (this->buffvalue() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(2, this->buffvalue(), output);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), output);
  }
  // @@protoc_insertion_point(serialize_end:protoMsg.MoraleInfo)
}

::google::protobuf::uint8* MoraleInfo::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:protoMsg.MoraleInfo)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // int32 camp = 1;
  if (this->camp() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, this->camp(), target);
  }

  // int32 buffvalue = 2;
  if (this->buffvalue() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, this->buffvalue(), target);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:protoMsg.MoraleInfo)
  return target;
}

size_t MoraleInfo::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:protoMsg.MoraleInfo)
  size_t total_size = 0;

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()));
  }
  // int32 camp = 1;
  if (this->camp() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->camp());
  }

  // int32 buffvalue = 2;
  if (this->buffvalue() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->buffvalue());
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void MoraleInfo::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:protoMsg.MoraleInfo)
  GOOGLE_DCHECK_NE(&from, this);
  const MoraleInfo* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const MoraleInfo>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:protoMsg.MoraleInfo)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:protoMsg.MoraleInfo)
    MergeFrom(*source);
  }
}

void MoraleInfo::MergeFrom(const MoraleInfo& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:protoMsg.MoraleInfo)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.camp() != 0) {
    set_camp(from.camp());
  }
  if (from.buffvalue() != 0) {
    set_buffvalue(from.buffvalue());
  }
}

void MoraleInfo::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:protoMsg.MoraleInfo)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void MoraleInfo::CopyFrom(const MoraleInfo& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:protoMsg.MoraleInfo)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool MoraleInfo::IsInitialized() const {
  return true;
}

void MoraleInfo::Swap(MoraleInfo* other) {
  if (other == this) return;
  InternalSwap(other);
}
void MoraleInfo::InternalSwap(MoraleInfo* other) {
  using std::swap;
  swap(camp_, other->camp_);
  swap(buffvalue_, other->buffvalue_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata MoraleInfo::GetMetadata() const {
  protobuf_level_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_level_2eproto::file_level_metadata[kIndexInFileMessages];
}


// ===================================================================

void MoraleInfoList::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int MoraleInfoList::kMoraleInfoFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

MoraleInfoList::MoraleInfoList()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  if (GOOGLE_PREDICT_TRUE(this != internal_default_instance())) {
    ::protobuf_level_2eproto::InitDefaultsMoraleInfoList();
  }
  SharedCtor();
  // @@protoc_insertion_point(constructor:protoMsg.MoraleInfoList)
}
MoraleInfoList::MoraleInfoList(const MoraleInfoList& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      moraleinfo_(from.moraleinfo_),
      _cached_size_(0) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  // @@protoc_insertion_point(copy_constructor:protoMsg.MoraleInfoList)
}

void MoraleInfoList::SharedCtor() {
  _cached_size_ = 0;
}

MoraleInfoList::~MoraleInfoList() {
  // @@protoc_insertion_point(destructor:protoMsg.MoraleInfoList)
  SharedDtor();
}

void MoraleInfoList::SharedDtor() {
}

void MoraleInfoList::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* MoraleInfoList::descriptor() {
  ::protobuf_level_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_level_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const MoraleInfoList& MoraleInfoList::default_instance() {
  ::protobuf_level_2eproto::InitDefaultsMoraleInfoList();
  return *internal_default_instance();
}

MoraleInfoList* MoraleInfoList::New(::google::protobuf::Arena* arena) const {
  MoraleInfoList* n = new MoraleInfoList;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void MoraleInfoList::Clear() {
// @@protoc_insertion_point(message_clear_start:protoMsg.MoraleInfoList)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  moraleinfo_.Clear();
  _internal_metadata_.Clear();
}

bool MoraleInfoList::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:protoMsg.MoraleInfoList)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .protoMsg.MoraleInfo moraleInfo = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(10u /* 10 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_moraleinfo()));
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
  // @@protoc_insertion_point(parse_success:protoMsg.MoraleInfoList)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:protoMsg.MoraleInfoList)
  return false;
#undef DO_
}

void MoraleInfoList::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:protoMsg.MoraleInfoList)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated .protoMsg.MoraleInfo moraleInfo = 1;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->moraleinfo_size()); i < n; i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->moraleinfo(static_cast<int>(i)), output);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), output);
  }
  // @@protoc_insertion_point(serialize_end:protoMsg.MoraleInfoList)
}

::google::protobuf::uint8* MoraleInfoList::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:protoMsg.MoraleInfoList)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated .protoMsg.MoraleInfo moraleInfo = 1;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->moraleinfo_size()); i < n; i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      InternalWriteMessageNoVirtualToArray(
        1, this->moraleinfo(static_cast<int>(i)), deterministic, target);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:protoMsg.MoraleInfoList)
  return target;
}

size_t MoraleInfoList::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:protoMsg.MoraleInfoList)
  size_t total_size = 0;

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()));
  }
  // repeated .protoMsg.MoraleInfo moraleInfo = 1;
  {
    unsigned int count = static_cast<unsigned int>(this->moraleinfo_size());
    total_size += 1UL * count;
    for (unsigned int i = 0; i < count; i++) {
      total_size +=
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->moraleinfo(static_cast<int>(i)));
    }
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void MoraleInfoList::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:protoMsg.MoraleInfoList)
  GOOGLE_DCHECK_NE(&from, this);
  const MoraleInfoList* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const MoraleInfoList>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:protoMsg.MoraleInfoList)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:protoMsg.MoraleInfoList)
    MergeFrom(*source);
  }
}

void MoraleInfoList::MergeFrom(const MoraleInfoList& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:protoMsg.MoraleInfoList)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  moraleinfo_.MergeFrom(from.moraleinfo_);
}

void MoraleInfoList::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:protoMsg.MoraleInfoList)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void MoraleInfoList::CopyFrom(const MoraleInfoList& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:protoMsg.MoraleInfoList)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool MoraleInfoList::IsInitialized() const {
  return true;
}

void MoraleInfoList::Swap(MoraleInfoList* other) {
  if (other == this) return;
  InternalSwap(other);
}
void MoraleInfoList::InternalSwap(MoraleInfoList* other) {
  using std::swap;
  moraleinfo_.InternalSwap(&other->moraleinfo_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata MoraleInfoList::GetMetadata() const {
  protobuf_level_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_level_2eproto::file_level_metadata[kIndexInFileMessages];
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace protoMsg

// @@protoc_insertion_point(global_scope)
