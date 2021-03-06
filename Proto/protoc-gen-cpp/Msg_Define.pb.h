// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Msg_Define.proto

#ifndef PROTOBUF_Msg_5fDefine_2eproto__INCLUDED
#define PROTOBUF_Msg_5fDefine_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3004000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3004000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_reflection.h>
// @@protoc_insertion_point(includes)

namespace protobuf_Msg_5fDefine_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[1];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
inline void InitDefaults() {
}
}  // namespace protobuf_Msg_5fDefine_2eproto

enum EObjectType {
  OT_NONE = 0,
  OT_PLAYER = 1,
  OT_ROBOT = 2,
  OT_MONSTER = 3,
  OT_PET = 4,
  OT_PARTNER = 5,
  OT_SUMMON = 6,
  EObjectType_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  EObjectType_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool EObjectType_IsValid(int value);
const EObjectType EObjectType_MIN = OT_NONE;
const EObjectType EObjectType_MAX = OT_SUMMON;
const int EObjectType_ARRAYSIZE = EObjectType_MAX + 1;

const ::google::protobuf::EnumDescriptor* EObjectType_descriptor();
inline const ::std::string& EObjectType_Name(EObjectType value) {
  return ::google::protobuf::internal::NameOfEnum(
    EObjectType_descriptor(), value);
}
inline bool EObjectType_Parse(
    const ::std::string& name, EObjectType* value) {
  return ::google::protobuf::internal::ParseNamedEnum<EObjectType>(
    EObjectType_descriptor(), name, value);
}
enum EChatChannel {
  CHL_NONE = 0,
  CHL_WORLD = 1,
  CHL_PRIVATE = 2,
  CHL_GUILD = 3,
  CHL_GM = 4,
  EChatChannel_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  EChatChannel_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool EChatChannel_IsValid(int value);
const EChatChannel EChatChannel_MIN = CHL_NONE;
const EChatChannel EChatChannel_MAX = CHL_GM;
const int EChatChannel_ARRAYSIZE = EChatChannel_MAX + 1;

const ::google::protobuf::EnumDescriptor* EChatChannel_descriptor();
inline const ::std::string& EChatChannel_Name(EChatChannel value) {
  return ::google::protobuf::internal::NameOfEnum(
    EChatChannel_descriptor(), value);
}
inline bool EChatChannel_Parse(
    const ::std::string& name, EChatChannel* value) {
  return ::google::protobuf::internal::ParseNamedEnum<EChatChannel>(
    EChatChannel_descriptor(), name, value);
}
// ===================================================================


// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)


namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::EObjectType> : ::google::protobuf::internal::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::EObjectType>() {
  return ::EObjectType_descriptor();
}
template <> struct is_proto_enum< ::EChatChannel> : ::google::protobuf::internal::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::EChatChannel>() {
  return ::EChatChannel_descriptor();
}

}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_Msg_5fDefine_2eproto__INCLUDED
