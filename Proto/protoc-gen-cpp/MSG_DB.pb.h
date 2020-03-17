// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Msg_DB.proto

#ifndef PROTOBUF_Msg_5fDB_2eproto__INCLUDED
#define PROTOBUF_Msg_5fDB_2eproto__INCLUDED

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

namespace protobuf_Msg_5fDB_2eproto {
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
void InitDefaultsDBRoleDataImpl();
void InitDefaultsDBRoleData();
void InitDefaultsDBRoleLoginAckImpl();
void InitDefaultsDBRoleLoginAck();
inline void InitDefaults() {
  InitDefaultsDBRoleData();
  InitDefaultsDBRoleLoginAck();
}
}  // namespace protobuf_Msg_5fDB_2eproto
class DBRoleData;
class DBRoleDataDefaultTypeInternal;
extern DBRoleDataDefaultTypeInternal _DBRoleData_default_instance_;
class DBRoleLoginAck;
class DBRoleLoginAckDefaultTypeInternal;
extern DBRoleLoginAckDefaultTypeInternal _DBRoleLoginAck_default_instance_;

// ===================================================================

class DBRoleData : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:DBRoleData) */ {
 public:
  DBRoleData();
  virtual ~DBRoleData();

  DBRoleData(const DBRoleData& from);

  inline DBRoleData& operator=(const DBRoleData& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  DBRoleData(DBRoleData&& from) noexcept
    : DBRoleData() {
    *this = ::std::move(from);
  }

  inline DBRoleData& operator=(DBRoleData&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const DBRoleData& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const DBRoleData* internal_default_instance() {
    return reinterpret_cast<const DBRoleData*>(
               &_DBRoleData_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(DBRoleData* other);
  friend void swap(DBRoleData& a, DBRoleData& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline DBRoleData* New() const PROTOBUF_FINAL { return New(NULL); }

  DBRoleData* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const DBRoleData& from);
  void MergeFrom(const DBRoleData& from);
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
  void InternalSwap(DBRoleData* other);
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

  // repeated int64 Action = 12;
  int action_size() const;
  void clear_action();
  static const int kActionFieldNumber = 12;
  ::google::protobuf::int64 action(int index) const;
  void set_action(int index, ::google::protobuf::int64 value);
  void add_action(::google::protobuf::int64 value);
  const ::google::protobuf::RepeatedField< ::google::protobuf::int64 >&
      action() const;
  ::google::protobuf::RepeatedField< ::google::protobuf::int64 >*
      mutable_action();

  // repeated int64 Actime = 13;
  int actime_size() const;
  void clear_actime();
  static const int kActimeFieldNumber = 13;
  ::google::protobuf::int64 actime(int index) const;
  void set_actime(int index, ::google::protobuf::int64 value);
  void add_actime(::google::protobuf::int64 value);
  const ::google::protobuf::RepeatedField< ::google::protobuf::int64 >&
      actime() const;
  ::google::protobuf::RepeatedField< ::google::protobuf::int64 >*
      mutable_actime();

  // string Name = 6;
  void clear_name();
  static const int kNameFieldNumber = 6;
  const ::std::string& name() const;
  void set_name(const ::std::string& value);
  #if LANG_CXX11
  void set_name(::std::string&& value);
  #endif
  void set_name(const char* value);
  void set_name(const char* value, size_t size);
  ::std::string* mutable_name();
  ::std::string* release_name();
  void set_allocated_name(::std::string* name);

  // uint64 AccountID = 1;
  void clear_accountid();
  static const int kAccountIDFieldNumber = 1;
  ::google::protobuf::uint64 accountid() const;
  void set_accountid(::google::protobuf::uint64 value);

  // uint64 RoleID = 2;
  void clear_roleid();
  static const int kRoleIDFieldNumber = 2;
  ::google::protobuf::uint64 roleid() const;
  void set_roleid(::google::protobuf::uint64 value);

  // int32 CarrerID = 3;
  void clear_carrerid();
  static const int kCarrerIDFieldNumber = 3;
  ::google::protobuf::int32 carrerid() const;
  void set_carrerid(::google::protobuf::int32 value);

  // int32 Level = 4;
  void clear_level();
  static const int kLevelFieldNumber = 4;
  ::google::protobuf::int32 level() const;
  void set_level(::google::protobuf::int32 value);

  // int64 Exp = 5;
  void clear_exp();
  static const int kExpFieldNumber = 5;
  ::google::protobuf::int64 exp() const;
  void set_exp(::google::protobuf::int64 value);

  // int32 LangID = 7;
  void clear_langid();
  static const int kLangIDFieldNumber = 7;
  ::google::protobuf::int32 langid() const;
  void set_langid(::google::protobuf::int32 value);

  // int32 VipLvl = 8;
  void clear_viplvl();
  static const int kVipLvlFieldNumber = 8;
  ::google::protobuf::int32 viplvl() const;
  void set_viplvl(::google::protobuf::int32 value);

  // int64 FightValue = 10;
  void clear_fightvalue();
  static const int kFightValueFieldNumber = 10;
  ::google::protobuf::int64 fightvalue() const;
  void set_fightvalue(::google::protobuf::int64 value);

  // int32 VipExp = 9;
  void clear_vipexp();
  static const int kVipExpFieldNumber = 9;
  ::google::protobuf::int32 vipexp() const;
  void set_vipexp(::google::protobuf::int32 value);

  // int32 CityCopyID = 11;
  void clear_citycopyid();
  static const int kCityCopyIDFieldNumber = 11;
  ::google::protobuf::int32 citycopyid() const;
  void set_citycopyid(::google::protobuf::int32 value);

  // uint64 CreateTime = 14;
  void clear_createtime();
  static const int kCreateTimeFieldNumber = 14;
  ::google::protobuf::uint64 createtime() const;
  void set_createtime(::google::protobuf::uint64 value);

  // uint64 LogonTime = 15;
  void clear_logontime();
  static const int kLogonTimeFieldNumber = 15;
  ::google::protobuf::uint64 logontime() const;
  void set_logontime(::google::protobuf::uint64 value);

  // uint64 LogoffTime = 16;
  void clear_logofftime();
  static const int kLogoffTimeFieldNumber = 16;
  ::google::protobuf::uint64 logofftime() const;
  void set_logofftime(::google::protobuf::uint64 value);

  // @@protoc_insertion_point(class_scope:DBRoleData)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::RepeatedField< ::google::protobuf::int64 > action_;
  mutable int _action_cached_byte_size_;
  ::google::protobuf::RepeatedField< ::google::protobuf::int64 > actime_;
  mutable int _actime_cached_byte_size_;
  ::google::protobuf::internal::ArenaStringPtr name_;
  ::google::protobuf::uint64 accountid_;
  ::google::protobuf::uint64 roleid_;
  ::google::protobuf::int32 carrerid_;
  ::google::protobuf::int32 level_;
  ::google::protobuf::int64 exp_;
  ::google::protobuf::int32 langid_;
  ::google::protobuf::int32 viplvl_;
  ::google::protobuf::int64 fightvalue_;
  ::google::protobuf::int32 vipexp_;
  ::google::protobuf::int32 citycopyid_;
  ::google::protobuf::uint64 createtime_;
  ::google::protobuf::uint64 logontime_;
  ::google::protobuf::uint64 logofftime_;
  mutable int _cached_size_;
  friend struct ::protobuf_Msg_5fDB_2eproto::TableStruct;
  friend void ::protobuf_Msg_5fDB_2eproto::InitDefaultsDBRoleDataImpl();
};
// -------------------------------------------------------------------

class DBRoleLoginAck : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:DBRoleLoginAck) */ {
 public:
  DBRoleLoginAck();
  virtual ~DBRoleLoginAck();

  DBRoleLoginAck(const DBRoleLoginAck& from);

  inline DBRoleLoginAck& operator=(const DBRoleLoginAck& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  DBRoleLoginAck(DBRoleLoginAck&& from) noexcept
    : DBRoleLoginAck() {
    *this = ::std::move(from);
  }

  inline DBRoleLoginAck& operator=(DBRoleLoginAck&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const DBRoleLoginAck& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const DBRoleLoginAck* internal_default_instance() {
    return reinterpret_cast<const DBRoleLoginAck*>(
               &_DBRoleLoginAck_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    1;

  void Swap(DBRoleLoginAck* other);
  friend void swap(DBRoleLoginAck& a, DBRoleLoginAck& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline DBRoleLoginAck* New() const PROTOBUF_FINAL { return New(NULL); }

  DBRoleLoginAck* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const DBRoleLoginAck& from);
  void MergeFrom(const DBRoleLoginAck& from);
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
  void InternalSwap(DBRoleLoginAck* other);
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

  // .DBRoleData RoleData = 3;
  bool has_roledata() const;
  void clear_roledata();
  static const int kRoleDataFieldNumber = 3;
  const ::DBRoleData& roledata() const;
  ::DBRoleData* mutable_roledata();
  ::DBRoleData* release_roledata();
  void set_allocated_roledata(::DBRoleData* roledata);

  // uint64 RoleID = 2;
  void clear_roleid();
  static const int kRoleIDFieldNumber = 2;
  ::google::protobuf::uint64 roleid() const;
  void set_roleid(::google::protobuf::uint64 value);

  // uint32 RetCode = 1;
  void clear_retcode();
  static const int kRetCodeFieldNumber = 1;
  ::google::protobuf::uint32 retcode() const;
  void set_retcode(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:DBRoleLoginAck)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::DBRoleData* roledata_;
  ::google::protobuf::uint64 roleid_;
  ::google::protobuf::uint32 retcode_;
  mutable int _cached_size_;
  friend struct ::protobuf_Msg_5fDB_2eproto::TableStruct;
  friend void ::protobuf_Msg_5fDB_2eproto::InitDefaultsDBRoleLoginAckImpl();
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// DBRoleData

// uint64 AccountID = 1;
inline void DBRoleData::clear_accountid() {
  accountid_ = GOOGLE_ULONGLONG(0);
}
inline ::google::protobuf::uint64 DBRoleData::accountid() const {
  // @@protoc_insertion_point(field_get:DBRoleData.AccountID)
  return accountid_;
}
inline void DBRoleData::set_accountid(::google::protobuf::uint64 value) {
  
  accountid_ = value;
  // @@protoc_insertion_point(field_set:DBRoleData.AccountID)
}

// uint64 RoleID = 2;
inline void DBRoleData::clear_roleid() {
  roleid_ = GOOGLE_ULONGLONG(0);
}
inline ::google::protobuf::uint64 DBRoleData::roleid() const {
  // @@protoc_insertion_point(field_get:DBRoleData.RoleID)
  return roleid_;
}
inline void DBRoleData::set_roleid(::google::protobuf::uint64 value) {
  
  roleid_ = value;
  // @@protoc_insertion_point(field_set:DBRoleData.RoleID)
}

// int32 CarrerID = 3;
inline void DBRoleData::clear_carrerid() {
  carrerid_ = 0;
}
inline ::google::protobuf::int32 DBRoleData::carrerid() const {
  // @@protoc_insertion_point(field_get:DBRoleData.CarrerID)
  return carrerid_;
}
inline void DBRoleData::set_carrerid(::google::protobuf::int32 value) {
  
  carrerid_ = value;
  // @@protoc_insertion_point(field_set:DBRoleData.CarrerID)
}

// int32 Level = 4;
inline void DBRoleData::clear_level() {
  level_ = 0;
}
inline ::google::protobuf::int32 DBRoleData::level() const {
  // @@protoc_insertion_point(field_get:DBRoleData.Level)
  return level_;
}
inline void DBRoleData::set_level(::google::protobuf::int32 value) {
  
  level_ = value;
  // @@protoc_insertion_point(field_set:DBRoleData.Level)
}

// int64 Exp = 5;
inline void DBRoleData::clear_exp() {
  exp_ = GOOGLE_LONGLONG(0);
}
inline ::google::protobuf::int64 DBRoleData::exp() const {
  // @@protoc_insertion_point(field_get:DBRoleData.Exp)
  return exp_;
}
inline void DBRoleData::set_exp(::google::protobuf::int64 value) {
  
  exp_ = value;
  // @@protoc_insertion_point(field_set:DBRoleData.Exp)
}

// string Name = 6;
inline void DBRoleData::clear_name() {
  name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& DBRoleData::name() const {
  // @@protoc_insertion_point(field_get:DBRoleData.Name)
  return name_.GetNoArena();
}
inline void DBRoleData::set_name(const ::std::string& value) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:DBRoleData.Name)
}
#if LANG_CXX11
inline void DBRoleData::set_name(::std::string&& value) {
  
  name_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:DBRoleData.Name)
}
#endif
inline void DBRoleData::set_name(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:DBRoleData.Name)
}
inline void DBRoleData::set_name(const char* value, size_t size) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:DBRoleData.Name)
}
inline ::std::string* DBRoleData::mutable_name() {
  
  // @@protoc_insertion_point(field_mutable:DBRoleData.Name)
  return name_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* DBRoleData::release_name() {
  // @@protoc_insertion_point(field_release:DBRoleData.Name)
  
  return name_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void DBRoleData::set_allocated_name(::std::string* name) {
  if (name != NULL) {
    
  } else {
    
  }
  name_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), name);
  // @@protoc_insertion_point(field_set_allocated:DBRoleData.Name)
}

// int32 LangID = 7;
inline void DBRoleData::clear_langid() {
  langid_ = 0;
}
inline ::google::protobuf::int32 DBRoleData::langid() const {
  // @@protoc_insertion_point(field_get:DBRoleData.LangID)
  return langid_;
}
inline void DBRoleData::set_langid(::google::protobuf::int32 value) {
  
  langid_ = value;
  // @@protoc_insertion_point(field_set:DBRoleData.LangID)
}

// int32 VipLvl = 8;
inline void DBRoleData::clear_viplvl() {
  viplvl_ = 0;
}
inline ::google::protobuf::int32 DBRoleData::viplvl() const {
  // @@protoc_insertion_point(field_get:DBRoleData.VipLvl)
  return viplvl_;
}
inline void DBRoleData::set_viplvl(::google::protobuf::int32 value) {
  
  viplvl_ = value;
  // @@protoc_insertion_point(field_set:DBRoleData.VipLvl)
}

// int32 VipExp = 9;
inline void DBRoleData::clear_vipexp() {
  vipexp_ = 0;
}
inline ::google::protobuf::int32 DBRoleData::vipexp() const {
  // @@protoc_insertion_point(field_get:DBRoleData.VipExp)
  return vipexp_;
}
inline void DBRoleData::set_vipexp(::google::protobuf::int32 value) {
  
  vipexp_ = value;
  // @@protoc_insertion_point(field_set:DBRoleData.VipExp)
}

// int64 FightValue = 10;
inline void DBRoleData::clear_fightvalue() {
  fightvalue_ = GOOGLE_LONGLONG(0);
}
inline ::google::protobuf::int64 DBRoleData::fightvalue() const {
  // @@protoc_insertion_point(field_get:DBRoleData.FightValue)
  return fightvalue_;
}
inline void DBRoleData::set_fightvalue(::google::protobuf::int64 value) {
  
  fightvalue_ = value;
  // @@protoc_insertion_point(field_set:DBRoleData.FightValue)
}

// int32 CityCopyID = 11;
inline void DBRoleData::clear_citycopyid() {
  citycopyid_ = 0;
}
inline ::google::protobuf::int32 DBRoleData::citycopyid() const {
  // @@protoc_insertion_point(field_get:DBRoleData.CityCopyID)
  return citycopyid_;
}
inline void DBRoleData::set_citycopyid(::google::protobuf::int32 value) {
  
  citycopyid_ = value;
  // @@protoc_insertion_point(field_set:DBRoleData.CityCopyID)
}

// repeated int64 Action = 12;
inline int DBRoleData::action_size() const {
  return action_.size();
}
inline void DBRoleData::clear_action() {
  action_.Clear();
}
inline ::google::protobuf::int64 DBRoleData::action(int index) const {
  // @@protoc_insertion_point(field_get:DBRoleData.Action)
  return action_.Get(index);
}
inline void DBRoleData::set_action(int index, ::google::protobuf::int64 value) {
  action_.Set(index, value);
  // @@protoc_insertion_point(field_set:DBRoleData.Action)
}
inline void DBRoleData::add_action(::google::protobuf::int64 value) {
  action_.Add(value);
  // @@protoc_insertion_point(field_add:DBRoleData.Action)
}
inline const ::google::protobuf::RepeatedField< ::google::protobuf::int64 >&
DBRoleData::action() const {
  // @@protoc_insertion_point(field_list:DBRoleData.Action)
  return action_;
}
inline ::google::protobuf::RepeatedField< ::google::protobuf::int64 >*
DBRoleData::mutable_action() {
  // @@protoc_insertion_point(field_mutable_list:DBRoleData.Action)
  return &action_;
}

// repeated int64 Actime = 13;
inline int DBRoleData::actime_size() const {
  return actime_.size();
}
inline void DBRoleData::clear_actime() {
  actime_.Clear();
}
inline ::google::protobuf::int64 DBRoleData::actime(int index) const {
  // @@protoc_insertion_point(field_get:DBRoleData.Actime)
  return actime_.Get(index);
}
inline void DBRoleData::set_actime(int index, ::google::protobuf::int64 value) {
  actime_.Set(index, value);
  // @@protoc_insertion_point(field_set:DBRoleData.Actime)
}
inline void DBRoleData::add_actime(::google::protobuf::int64 value) {
  actime_.Add(value);
  // @@protoc_insertion_point(field_add:DBRoleData.Actime)
}
inline const ::google::protobuf::RepeatedField< ::google::protobuf::int64 >&
DBRoleData::actime() const {
  // @@protoc_insertion_point(field_list:DBRoleData.Actime)
  return actime_;
}
inline ::google::protobuf::RepeatedField< ::google::protobuf::int64 >*
DBRoleData::mutable_actime() {
  // @@protoc_insertion_point(field_mutable_list:DBRoleData.Actime)
  return &actime_;
}

// uint64 CreateTime = 14;
inline void DBRoleData::clear_createtime() {
  createtime_ = GOOGLE_ULONGLONG(0);
}
inline ::google::protobuf::uint64 DBRoleData::createtime() const {
  // @@protoc_insertion_point(field_get:DBRoleData.CreateTime)
  return createtime_;
}
inline void DBRoleData::set_createtime(::google::protobuf::uint64 value) {
  
  createtime_ = value;
  // @@protoc_insertion_point(field_set:DBRoleData.CreateTime)
}

// uint64 LogonTime = 15;
inline void DBRoleData::clear_logontime() {
  logontime_ = GOOGLE_ULONGLONG(0);
}
inline ::google::protobuf::uint64 DBRoleData::logontime() const {
  // @@protoc_insertion_point(field_get:DBRoleData.LogonTime)
  return logontime_;
}
inline void DBRoleData::set_logontime(::google::protobuf::uint64 value) {
  
  logontime_ = value;
  // @@protoc_insertion_point(field_set:DBRoleData.LogonTime)
}

// uint64 LogoffTime = 16;
inline void DBRoleData::clear_logofftime() {
  logofftime_ = GOOGLE_ULONGLONG(0);
}
inline ::google::protobuf::uint64 DBRoleData::logofftime() const {
  // @@protoc_insertion_point(field_get:DBRoleData.LogoffTime)
  return logofftime_;
}
inline void DBRoleData::set_logofftime(::google::protobuf::uint64 value) {
  
  logofftime_ = value;
  // @@protoc_insertion_point(field_set:DBRoleData.LogoffTime)
}

// -------------------------------------------------------------------

// DBRoleLoginAck

// uint32 RetCode = 1;
inline void DBRoleLoginAck::clear_retcode() {
  retcode_ = 0u;
}
inline ::google::protobuf::uint32 DBRoleLoginAck::retcode() const {
  // @@protoc_insertion_point(field_get:DBRoleLoginAck.RetCode)
  return retcode_;
}
inline void DBRoleLoginAck::set_retcode(::google::protobuf::uint32 value) {
  
  retcode_ = value;
  // @@protoc_insertion_point(field_set:DBRoleLoginAck.RetCode)
}

// uint64 RoleID = 2;
inline void DBRoleLoginAck::clear_roleid() {
  roleid_ = GOOGLE_ULONGLONG(0);
}
inline ::google::protobuf::uint64 DBRoleLoginAck::roleid() const {
  // @@protoc_insertion_point(field_get:DBRoleLoginAck.RoleID)
  return roleid_;
}
inline void DBRoleLoginAck::set_roleid(::google::protobuf::uint64 value) {
  
  roleid_ = value;
  // @@protoc_insertion_point(field_set:DBRoleLoginAck.RoleID)
}

// .DBRoleData RoleData = 3;
inline bool DBRoleLoginAck::has_roledata() const {
  return this != internal_default_instance() && roledata_ != NULL;
}
inline void DBRoleLoginAck::clear_roledata() {
  if (GetArenaNoVirtual() == NULL && roledata_ != NULL) delete roledata_;
  roledata_ = NULL;
}
inline const ::DBRoleData& DBRoleLoginAck::roledata() const {
  const ::DBRoleData* p = roledata_;
  // @@protoc_insertion_point(field_get:DBRoleLoginAck.RoleData)
  return p != NULL ? *p : *reinterpret_cast<const ::DBRoleData*>(
      &::_DBRoleData_default_instance_);
}
inline ::DBRoleData* DBRoleLoginAck::mutable_roledata() {
  
  if (roledata_ == NULL) {
    roledata_ = new ::DBRoleData;
  }
  // @@protoc_insertion_point(field_mutable:DBRoleLoginAck.RoleData)
  return roledata_;
}
inline ::DBRoleData* DBRoleLoginAck::release_roledata() {
  // @@protoc_insertion_point(field_release:DBRoleLoginAck.RoleData)
  
  ::DBRoleData* temp = roledata_;
  roledata_ = NULL;
  return temp;
}
inline void DBRoleLoginAck::set_allocated_roledata(::DBRoleData* roledata) {
  delete roledata_;
  roledata_ = roledata;
  if (roledata) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:DBRoleLoginAck.RoleData)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_Msg_5fDB_2eproto__INCLUDED
