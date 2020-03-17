// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: level.proto

#ifndef PROTOBUF_level_2eproto__INCLUDED
#define PROTOBUF_level_2eproto__INCLUDED

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
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace protobuf_level_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[2];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
void InitDefaultsMoraleInfoImpl();
void InitDefaultsMoraleInfo();
void InitDefaultsMoraleInfoListImpl();
void InitDefaultsMoraleInfoList();
inline void InitDefaults() {
  InitDefaultsMoraleInfo();
  InitDefaultsMoraleInfoList();
}
}  // namespace protobuf_level_2eproto
namespace protoMsg {
class MoraleInfo;
class MoraleInfoDefaultTypeInternal;
extern MoraleInfoDefaultTypeInternal _MoraleInfo_default_instance_;
class MoraleInfoList;
class MoraleInfoListDefaultTypeInternal;
extern MoraleInfoListDefaultTypeInternal _MoraleInfoList_default_instance_;
}  // namespace protoMsg
namespace protoMsg {

// ===================================================================

class MoraleInfo : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:protoMsg.MoraleInfo) */ {
 public:
  MoraleInfo();
  virtual ~MoraleInfo();

  MoraleInfo(const MoraleInfo& from);

  inline MoraleInfo& operator=(const MoraleInfo& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  MoraleInfo(MoraleInfo&& from) noexcept
    : MoraleInfo() {
    *this = ::std::move(from);
  }

  inline MoraleInfo& operator=(MoraleInfo&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const MoraleInfo& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const MoraleInfo* internal_default_instance() {
    return reinterpret_cast<const MoraleInfo*>(
               &_MoraleInfo_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(MoraleInfo* other);
  friend void swap(MoraleInfo& a, MoraleInfo& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline MoraleInfo* New() const PROTOBUF_FINAL { return New(NULL); }

  MoraleInfo* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const MoraleInfo& from);
  void MergeFrom(const MoraleInfo& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(MoraleInfo* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // int32 camp = 1;
  void clear_camp();
  static const int kCampFieldNumber = 1;
  ::google::protobuf::int32 camp() const;
  void set_camp(::google::protobuf::int32 value);

  // int32 buffvalue = 2;
  void clear_buffvalue();
  static const int kBuffvalueFieldNumber = 2;
  ::google::protobuf::int32 buffvalue() const;
  void set_buffvalue(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:protoMsg.MoraleInfo)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::int32 camp_;
  ::google::protobuf::int32 buffvalue_;
  mutable int _cached_size_;
  friend struct ::protobuf_level_2eproto::TableStruct;
  friend void ::protobuf_level_2eproto::InitDefaultsMoraleInfoImpl();
};
// -------------------------------------------------------------------

class MoraleInfoList : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:protoMsg.MoraleInfoList) */ {
 public:
  MoraleInfoList();
  virtual ~MoraleInfoList();

  MoraleInfoList(const MoraleInfoList& from);

  inline MoraleInfoList& operator=(const MoraleInfoList& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  MoraleInfoList(MoraleInfoList&& from) noexcept
    : MoraleInfoList() {
    *this = ::std::move(from);
  }

  inline MoraleInfoList& operator=(MoraleInfoList&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const MoraleInfoList& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const MoraleInfoList* internal_default_instance() {
    return reinterpret_cast<const MoraleInfoList*>(
               &_MoraleInfoList_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    1;

  void Swap(MoraleInfoList* other);
  friend void swap(MoraleInfoList& a, MoraleInfoList& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline MoraleInfoList* New() const PROTOBUF_FINAL { return New(NULL); }

  MoraleInfoList* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const MoraleInfoList& from);
  void MergeFrom(const MoraleInfoList& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(MoraleInfoList* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // repeated .protoMsg.MoraleInfo moraleInfo = 1;
  int moraleinfo_size() const;
  void clear_moraleinfo();
  static const int kMoraleInfoFieldNumber = 1;
  const ::protoMsg::MoraleInfo& moraleinfo(int index) const;
  ::protoMsg::MoraleInfo* mutable_moraleinfo(int index);
  ::protoMsg::MoraleInfo* add_moraleinfo();
  ::google::protobuf::RepeatedPtrField< ::protoMsg::MoraleInfo >*
      mutable_moraleinfo();
  const ::google::protobuf::RepeatedPtrField< ::protoMsg::MoraleInfo >&
      moraleinfo() const;

  // @@protoc_insertion_point(class_scope:protoMsg.MoraleInfoList)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::RepeatedPtrField< ::protoMsg::MoraleInfo > moraleinfo_;
  mutable int _cached_size_;
  friend struct ::protobuf_level_2eproto::TableStruct;
  friend void ::protobuf_level_2eproto::InitDefaultsMoraleInfoListImpl();
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// MoraleInfo

// int32 camp = 1;
inline void MoraleInfo::clear_camp() {
  camp_ = 0;
}
inline ::google::protobuf::int32 MoraleInfo::camp() const {
  // @@protoc_insertion_point(field_get:protoMsg.MoraleInfo.camp)
  return camp_;
}
inline void MoraleInfo::set_camp(::google::protobuf::int32 value) {
  
  camp_ = value;
  // @@protoc_insertion_point(field_set:protoMsg.MoraleInfo.camp)
}

// int32 buffvalue = 2;
inline void MoraleInfo::clear_buffvalue() {
  buffvalue_ = 0;
}
inline ::google::protobuf::int32 MoraleInfo::buffvalue() const {
  // @@protoc_insertion_point(field_get:protoMsg.MoraleInfo.buffvalue)
  return buffvalue_;
}
inline void MoraleInfo::set_buffvalue(::google::protobuf::int32 value) {
  
  buffvalue_ = value;
  // @@protoc_insertion_point(field_set:protoMsg.MoraleInfo.buffvalue)
}

// -------------------------------------------------------------------

// MoraleInfoList

// repeated .protoMsg.MoraleInfo moraleInfo = 1;
inline int MoraleInfoList::moraleinfo_size() const {
  return moraleinfo_.size();
}
inline void MoraleInfoList::clear_moraleinfo() {
  moraleinfo_.Clear();
}
inline const ::protoMsg::MoraleInfo& MoraleInfoList::moraleinfo(int index) const {
  // @@protoc_insertion_point(field_get:protoMsg.MoraleInfoList.moraleInfo)
  return moraleinfo_.Get(index);
}
inline ::protoMsg::MoraleInfo* MoraleInfoList::mutable_moraleinfo(int index) {
  // @@protoc_insertion_point(field_mutable:protoMsg.MoraleInfoList.moraleInfo)
  return moraleinfo_.Mutable(index);
}
inline ::protoMsg::MoraleInfo* MoraleInfoList::add_moraleinfo() {
  // @@protoc_insertion_point(field_add:protoMsg.MoraleInfoList.moraleInfo)
  return moraleinfo_.Add();
}
inline ::google::protobuf::RepeatedPtrField< ::protoMsg::MoraleInfo >*
MoraleInfoList::mutable_moraleinfo() {
  // @@protoc_insertion_point(field_mutable_list:protoMsg.MoraleInfoList.moraleInfo)
  return &moraleinfo_;
}
inline const ::google::protobuf::RepeatedPtrField< ::protoMsg::MoraleInfo >&
MoraleInfoList::moraleinfo() const {
  // @@protoc_insertion_point(field_list:protoMsg.MoraleInfoList.moraleInfo)
  return moraleinfo_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace protoMsg

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_level_2eproto__INCLUDED
