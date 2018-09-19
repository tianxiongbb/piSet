#ifndef SERIALBASE__HPP
#define SERIALBASE__HPP

/*  $Id: serialbase.hpp 498023 2016-04-12 18:53:26Z grichenk $
* ===========================================================================
*
*                            PUBLIC DOMAIN NOTICE
*               National Center for Biotechnology Information
*
*  This software/database is a "United States Government Work" under the
*  terms of the United States Copyright Act.  It was written as part of
*  the author's official duties as a United States Government employee and
*  thus cannot be copyrighted.  This software/database is freely available
*  to the public for use. The National Library of Medicine and the U.S.
*  Government have not placed any restriction on its use or reproduction.
*
*  Although all reasonable efforts have been taken to ensure the accuracy
*  and reliability of the software and data, the NLM and the U.S.
*  Government do not and cannot warrant the performance or results that
*  may be obtained by using this software or data. The NLM and the U.S.
*  Government disclaim all warranties, express or implied, including
*  warranties of performance, merchantability or fitness for any particular
*  purpose.
*
*  Please cite the author in any work or product based on this material.
*
* ===========================================================================
*
* Author: Eugene Vasilchenko
*
* File Description:
*   File to be included in all headers generated by datatool
*/

#include <corelib/ncbistd.hpp>
#include <corelib/ncbiobj.hpp>
#include <serial/exception.hpp>
#include <serial/serialdef.hpp>
#include <serial/error_codes.hpp>
#include <typeinfo>

#define BITSTRING_AS_VECTOR    0

#if !BITSTRING_AS_VECTOR
#include <util/bitset/ncbi_bitset.hpp>
#include <util/bitset/bmserial.h>
#endif


/** @addtogroup GenClassSupport
 *
 * @{
 */


BEGIN_NCBI_SCOPE

// CBitString
#if BITSTRING_AS_VECTOR
typedef std::vector< bool > CBitString;
#else
typedef bm::bvector< > CBitString;
#endif

class CTypeInfo;
class CClassTypeInfo;
class CChoiceTypeInfo;
class CEnumeratedTypeValues;
class CObjectInfoCV;
class CObjectInfoMI;
class CReadClassMemberHook;
class CReadChoiceVariantHook;

// enum for choice classes generated by datatool
enum EResetVariant {
    eDoResetVariant,
    eDoNotResetVariant
};

typedef void (*TPreReadFunction)(const CTypeInfo* info, void* object);
typedef void (*TPostReadFunction)(const CTypeInfo* info, void* object);
typedef void (*TPreWriteFunction)(const CTypeInfo* info, const void* object);
typedef void (*TPostWriteFunction)(const CTypeInfo* info, const void* object);

NCBI_XSERIAL_EXPORT
void SetPreRead(CClassTypeInfo*  info, TPreReadFunction function);

NCBI_XSERIAL_EXPORT
void SetPostRead(CClassTypeInfo*  info, TPostReadFunction function);

NCBI_XSERIAL_EXPORT
void SetPreRead(CChoiceTypeInfo* info, TPreReadFunction function);

NCBI_XSERIAL_EXPORT
void SetPostRead(CChoiceTypeInfo* info, TPostReadFunction function);

NCBI_XSERIAL_EXPORT
void SetPreWrite(CClassTypeInfo*  info, TPreWriteFunction function);

NCBI_XSERIAL_EXPORT
void SetPostWrite(CClassTypeInfo*  info, TPostWriteFunction function);

NCBI_XSERIAL_EXPORT
void SetPreWrite(CChoiceTypeInfo* info, TPreWriteFunction function);

NCBI_XSERIAL_EXPORT
void SetPostWrite(CChoiceTypeInfo* info, TPostWriteFunction function);

NCBI_XSERIAL_EXPORT
void SetGlobalReadMemberHook(CTypeInfo* start_info,
                             const char* member_names,
                             CReadClassMemberHook* hook);

NCBI_XSERIAL_EXPORT
void SetGlobalReadVariantHook(CTypeInfo* start_info,
                              const char* variant_names,
                              CReadChoiceVariantHook* hook);

NCBI_XSERIAL_EXPORT
TObjectPtr GetClassObjectPtr(const CObjectInfoMI& member);

NCBI_XSERIAL_EXPORT
TObjectPtr GetChoiceObjectPtr(const CObjectInfoCV& variant);

template<class Class>
class CClassPrePostReadWrite
{
public:
    static void PreRead(const CTypeInfo* /*info*/, void* object)
        {
            static_cast<Class*>(object)->PreRead();
        }
    static void PostRead(const CTypeInfo* /*info*/, void* object)
        {
            static_cast<Class*>(object)->PostRead();
        }
    static void PreWrite(const CTypeInfo* /*info*/, const void* object)
        {
            static_cast<const Class*>(object)->PreWrite();
        }
    static void PostWrite(const CTypeInfo* /*info*/, const void* object)
        {
            static_cast<const Class*>(object)->PostWrite();
        }
};

/// Base class for all serializable objects
class NCBI_XSERIAL_EXPORT CSerialObject : public CObject
{
public:
    CSerialObject(void);
    virtual ~CSerialObject(void);
    virtual const CTypeInfo* GetThisTypeInfo(void) const = 0;
    /// Set object to copy of another one
    virtual void Assign(const CSerialObject& source,
                        ESerialRecursionMode how = eRecursive);
    /// Check if both objects contain the same values
    virtual bool Equals(const CSerialObject& object,
                        ESerialRecursionMode how = eRecursive) const;
    virtual void DebugDump(CDebugDumpContext ddc, unsigned int depth) const;

    void ThrowUnassigned(TMemberIndex index) const;
    void ThrowUnassigned(TMemberIndex index,
                         const char* file_name,
                         int file_line) const;
    // for all GetX() methods called in the current thread
    static  void SetVerifyDataThread(ESerialVerifyData verify);
    // for all GetX() methods called in the current process
    static  void SetVerifyDataGlobal(ESerialVerifyData verify);

    static const char* ms_UnassignedStr;
    static const char  ms_UnassignedByte;

    static string UnassignedString(void) {
        return ms_UnassignedStr;
    }
    static CStringUTF8 UnassignedStringUTF8(void) {
        return CUtf8::AsUTF8(UnassignedString(),eEncoding_UTF8);
    }
    static char UnassignedByte(void) {
        return ms_UnassignedByte;
    }

    /// Check if object data type has namespace name
    bool HasNamespaceName(void) const;
    /// Get namespace name
    const string& GetNamespaceName(void) const;

    /// Check if data type has namespace prefix
    bool HasNamespacePrefix(void) const;
    /// Get namespace prefix
    const string& GetNamespacePrefix(void) const;

private:
    static ESerialVerifyData x_GetVerifyData(void);
};

/// XML attribute information item
class NCBI_XSERIAL_EXPORT CSerialAttribInfoItem
{
public:
    CSerialAttribInfoItem(const string& name,
                          const string& ns_name, const CStringUTF8& value);
    CSerialAttribInfoItem(const CSerialAttribInfoItem& other);
    virtual ~CSerialAttribInfoItem(void);

    /// Get local name of the information item
    const string& GetName(void) const;
    /// Get namespace name of the information item
    const string& GetNamespaceName(void) const;
    /// Get normalized value of the information item
    const CStringUTF8& GetValue(void) const;
private:
    string m_Name;
    string m_NsName;
    CStringUTF8 m_Value;
};

/// Serializable object that stores any combination of parsable data
///
/// In DTD - elements with category ANY
/// In XML schema - element of an unspecified type ('any')
class NCBI_XSERIAL_EXPORT CAnyContentObject : public CSerialObject
{
public:
    CAnyContentObject(void);
    CAnyContentObject(const CAnyContentObject& other);
    virtual ~CAnyContentObject(void);

    virtual const CTypeInfo* GetThisTypeInfo(void) const
    { return GetTypeInfo(); }
    static const CTypeInfo* GetTypeInfo(void);

    void Reset(void);
    CAnyContentObject& operator= (const CAnyContentObject& other);
    bool operator== (const CAnyContentObject& other) const;

    /// Set local name
    void SetName(const string& name);
    /// Get local name
    const string& GetName(void) const;
    /// Set normalized value
    void SetValue(const CStringUTF8& value);
    /// Get normalized value
    const CStringUTF8& GetValue(void) const;

    /// Set namespace name
    void SetNamespaceName(const string& ns_name);
    /// Get namespace name
    const string& GetNamespaceName(void) const;
    /// Set namespace prefix
    void SetNamespacePrefix(const string& ns_prefix);
    /// Get namespace prefix
    const string& GetNamespacePrefix(void) const;

    /// Add attribute
    void AddAttribute(const string& name,
                      const string& ns_name, const CStringUTF8& value);
    /// Get object attributes
    const vector<CSerialAttribInfoItem>& GetAttributes(void) const;

private:
    void x_Copy(const CAnyContentObject& other);
    void x_Decode(const CStringUTF8& value);
    string m_Name;
    CStringUTF8 m_Value;
    string m_NsName;
    string m_NsPrefix;
    vector<CSerialAttribInfoItem> m_Attlist;
};

/// Base class for user-defined serializable classes
/// to allow for objects assignment and comparison.
///
/// EXAMPLE:
///   class CSeq_entry : public CSeq_entry_Base, CSerialUserOp
class NCBI_XSERIAL_EXPORT CSerialUserOp
{
    friend class CClassTypeInfo;
    friend class CChoiceTypeInfo;
public:
    virtual ~CSerialUserOp() { }
protected:
    /// Will be called after copying the datatool-generated members
    virtual void UserOp_Assign(const CSerialUserOp& source) = 0;
    /// Will be called after comparing the datatool-generated members
    virtual bool UserOp_Equals(const CSerialUserOp& object) const = 0;
};


/////////////////////////////////////////////////////////////////////
///
/// Alias wrapper templates
///

template <class TPrim>
class NCBI_XSERIAL_EXPORT CAliasBase
{
public:
    typedef CAliasBase<TPrim> TThis;

    CAliasBase(void) {}
    explicit CAliasBase(const TPrim& value)
        : m_Data(value) {}

    const TPrim& Get(void) const
        {
            return m_Data;
        }
    TPrim& Set(void)
        {
            return m_Data;
        }
    void Set(const TPrim& value)
        {
            m_Data = value;
        }
    operator TPrim(void) const
        {
            return m_Data;
        }

    TThis& operator*(void)
        {
            return *this;
        }
    TThis* operator->(void)
        {
            return this;
        }

    template<class T> bool operator<(const T& value) const
        {
            return m_Data < value;
        }
    template<class T> bool operator>(const T& value) const
        {
            return m_Data > value;
        }
    template<class T> bool operator==(const T& value) const
        {
            return m_Data == value;
        }
    template<class T> bool operator!=(const T& value) const
        {
            return m_Data != value;
        }

    static TConstObjectPtr GetDataPtr(const TThis* alias)
        {
            return &alias->m_Data;
        }

protected:
    TPrim m_Data;
};


template <class TStd>
class NCBI_XSERIAL_EXPORT CStdAliasBase : public CAliasBase<TStd>
{
    typedef CAliasBase<TStd> TParent;
    typedef CStdAliasBase<TStd> TThis;
public:
    CStdAliasBase(void)
        : TParent((TStd)0) {}
    explicit CStdAliasBase(const TStd& value)
        : TParent(value) {}
};


template <class TString>
class NCBI_XSERIAL_EXPORT CStringAliasBase : public CAliasBase<TString>
{
    typedef CAliasBase<TString> TParent;
    typedef CStringAliasBase<TString> TThis;
public:
    CStringAliasBase(void)
        : TParent() {}
    explicit CStringAliasBase(const TString& value)
        : TParent(value) {}
};


#ifdef NCBI_STRICT_GI
template <>
class NCBI_XSERIAL_EXPORT CStdAliasBase<CStrictId64> : public CAliasBase<CStrictId64>
{
    typedef CAliasBase<CStrictId64> TParent;
    typedef CStdAliasBase<CStrictId64> TThis;
public:
    CStdAliasBase(void)
        : TParent(CStrictId64()) {}
    explicit CStdAliasBase(const CStrictId64& value)
        : TParent(value) {}
};
#endif


template<typename T>
class CUnionBuffer
{   // char buffer support, used in choices
public:
    typedef T    TObject;                  // object type
    typedef char TBuffer[sizeof(TObject)]; // char buffer type

    // cast to object type
    TObject& operator*(void)
        {
            TObject* ptr = static_cast<TObject*>
                (static_cast<void*>(m_Buffer));
            return *ptr;
        }
    const TObject& operator*(void) const
        {
            const TObject* ptr = static_cast<const TObject*>
                (static_cast<const void*>(m_Buffer));
            return *ptr;
        }

    // construct/destruct object
    void Construct(void)
        {
            ::new(static_cast<void*>(m_Buffer)) TObject();
        }
    void Destruct(void)
        {
            (**this).~TObject();
        }
    
private:
    TBuffer m_Buffer;
};


/////////////////////////////////////////////////////////////////////
//
//  Assignment and comparison for serializable objects
//

/// Set object to copy of another one
template <class C>
C& SerialAssign(C& dest, const C& src, ESerialRecursionMode how = eRecursive)
{
    if ( typeid(src) != typeid(dest) ) {
        string msg("Assignment of incompatible types: ");
        msg += typeid(dest).name();
        msg += " = ";
        msg += typeid(src).name();
        NCBI_THROW(CSerialException,eIllegalCall, msg);
    }
    C::GetTypeInfo()->Assign(&dest, &src, how);
    return dest;
}

/// Compare serial objects
template <class C>
bool SerialEquals(const C& object1, const C& object2,
                  ESerialRecursionMode how = eRecursive)
{
    if ( typeid(object1) != typeid(object2) ) {
        string msg("Cannot compare types: ");
        msg += typeid(object1).name();
        msg += " == ";
        msg += typeid(object2).name();
        NCBI_THROW(CSerialException,eIllegalCall, msg);
    }
    return C::GetTypeInfo()->Equals(&object1, &object2, how);
}

/// Create on heap a clone of the source object
template <typename C>
C* SerialClone(const C& src)
{
    typename C::TTypeInfo type = C::GetTypeInfo();
    TObjectPtr obj = type->Create();
    type->Assign(obj, &src);
    return static_cast<C*>(obj);
}

/////////////////////////////////////////////////////////////////////////////
//
//  I/O stream manipulators and helpers for serializable objects
//

// Helper base class
class NCBI_XSERIAL_EXPORT MSerial_Flags
{
public:
    static bool HasSerialFormatting(CNcbiIos& io);

protected:
    MSerial_Flags(unsigned long all, unsigned long flags);
    MSerial_Flags(const MSerial_Flags& o) {m_All=o.m_All; m_Flags=o.m_Flags;}

    void SetFlags(CNcbiIos& io) const;
    void SetFormatFlags(unsigned long flags);

    friend CNcbiOstream& operator<< (CNcbiOstream& io, const MSerial_Flags& obj);
    friend CNcbiIstream& operator>> (CNcbiIstream& io, const MSerial_Flags& obj);

private:
    MSerial_Flags(void);
    MSerial_Flags& operator= (const MSerial_Flags&);

    unsigned long m_All;
    unsigned long m_Flags;
};

inline
CNcbiOstream& operator<< (CNcbiOstream& io, const MSerial_Flags& obj)
{
    obj.SetFlags(io);
    return io;
}
inline
CNcbiIstream& operator>> (CNcbiIstream& io, const MSerial_Flags& obj)
{
    obj.SetFlags(io);
    return io;
}

/// MSerial_Format --
///
///   I/O stream manipulator. Set the format of output or input.
///   Makes it possible to insert or extract serializable objects directly
///   into standard I/O streams, hiding the creation of object streams.
///   For example:
///     cout << MSerial_Format(eSerial_Xml) << obj;
///   @sa ESerialDataFormat
typedef unsigned int TSerial_Format_Flags;
class NCBI_XSERIAL_EXPORT MSerial_Format : public MSerial_Flags
{
public:
    explicit MSerial_Format(ESerialDataFormat fmt, TSerial_Format_Flags flags = 0);
};

class NCBI_XSERIAL_EXPORT MSerial_Format_AsnText : public MSerial_Format
{
public:
    MSerial_Format_AsnText(void) : MSerial_Format(eSerial_AsnText) {}
    MSerial_Format& operator()(TSerial_AsnText_Flags flags);
};

class NCBI_XSERIAL_EXPORT MSerial_Format_AsnBinary : public MSerial_Format
{
public:
    MSerial_Format_AsnBinary(void) : MSerial_Format(eSerial_AsnBinary) {}
};

class NCBI_XSERIAL_EXPORT MSerial_Format_Xml : public MSerial_Format
{
public:
    MSerial_Format_Xml(void) : MSerial_Format(eSerial_Xml) {}
    MSerial_Format& operator()(TSerial_Xml_Flags flags);
};

class NCBI_XSERIAL_EXPORT MSerial_Format_Json : public MSerial_Format
{
public:
    MSerial_Format_Json(void) : MSerial_Format(eSerial_Json) {}
    MSerial_Format& operator()(TSerial_Json_Flags flags);
};

/// MSerial_VerifyData --
///
///   I/O stream manipulator. Defines verification of un-initialized data members.
///   For example:
///     cout << MSerial_Format(eSerial_Xml)
///          << MSerial_VerifyData(eSerialVerifyData_No) << obj;
///   @sa ESerialVerifyData
class NCBI_XSERIAL_EXPORT MSerial_VerifyData : public MSerial_Flags
{
public:
    explicit MSerial_VerifyData(ESerialVerifyData fmt);
};

/// MSerial_SkipUnknownMembers --
///
///   I/O stream manipulator. Set up skipping unknown members policy.
///   For example:
///     cin >> MSerial_Format(eSerial_Xml)
///         >> MSerial_SkipUnknownMembers(eSerialSkipUnknown_Yes) >> obj;
///   @sa ESerialSkipUnknown
class NCBI_XSERIAL_EXPORT MSerial_SkipUnknownMembers : protected MSerial_Flags
{
public:
    explicit MSerial_SkipUnknownMembers(ESerialSkipUnknown fmt);
    friend CNcbiIstream& operator>> (CNcbiIstream& io, const MSerial_SkipUnknownMembers& obj);
};
inline
CNcbiIstream& operator>> (CNcbiIstream& io, const MSerial_SkipUnknownMembers& obj)
{
    obj.SetFlags(io);
    return io;
}

/// MSerial_SkipUnknownVariants --
///
///   I/O stream manipulator. Set up skipping unknown choice variants policy.
///   For example:
///     cin >> MSerial_Format(eSerial_Xml)
///         >> MSerial_SkipUnknownVariants(eSerialSkipUnknown_Yes) >> obj;
///   @sa ESerialSkipUnknown
class NCBI_XSERIAL_EXPORT MSerial_SkipUnknownVariants : protected MSerial_Flags
{
public:
    explicit MSerial_SkipUnknownVariants(ESerialSkipUnknown fmt);
    friend CNcbiIstream& operator>> (CNcbiIstream& io, const MSerial_SkipUnknownVariants& obj);
};
inline
CNcbiIstream& operator>> (CNcbiIstream& io, const MSerial_SkipUnknownVariants& obj)
{
    obj.SetFlags(io);
    return io;
}

/// MSerialXml_DefaultStringEncoding --
///
///   I/O stream manipulator. Defines default string encoding in XML stream.
///   For example:
///     cout << MSerial_Format(eSerial_Xml)
///          << MSerialXml_DefaultStringEncoding(eEncoding_UTF8) << obj;
///   @sa EEncoding, CObjectOStreamXml, CObjectIStreamXml
class NCBI_XSERIAL_EXPORT MSerialXml_DefaultStringEncoding : public MSerial_Flags
{
public:
    explicit MSerialXml_DefaultStringEncoding(EEncoding fmt);
};

/// I/O stream manipulators --
///
///   Set the format of output or input.
///   Make it possible to insert or extract serializable objects directly
///   into standard I/O streams, hiding the creation of object streams.
///   For example:
///     cout << MSerial_Xml << obj;
///     cout << MSerial_Xml(fSerial_Xml_NoXmlDecl) << obj;
///     cin  >> MSerial_AsnText >> obj;

#define MSerial_AsnText   MSerial_Format_AsnText()
#define MSerial_AsnBinary MSerial_Format_AsnBinary()
#define MSerial_Xml       MSerial_Format_Xml()
#define MSerial_Json      MSerial_Format_Json()

/// Reset all formatting flags for the I/O stream
NCBI_XSERIAL_EXPORT CNcbiIos& MSerial_None(CNcbiIos& io);

/// Define verification of un-initialized data members.
NCBI_XSERIAL_EXPORT CNcbiIos& MSerial_VerifyDefault( CNcbiIos& io);
NCBI_XSERIAL_EXPORT CNcbiIos& MSerial_VerifyNo(      CNcbiIos& io);
NCBI_XSERIAL_EXPORT CNcbiIos& MSerial_VerifyYes(     CNcbiIos& io);
NCBI_XSERIAL_EXPORT CNcbiIos& MSerial_VerifyDefValue(CNcbiIos& io);

class CConstObjectInfo;
class CObjectInfo;
// Input/output
NCBI_XSERIAL_EXPORT CNcbiOstream& operator<< (CNcbiOstream& str, const CSerialObject&    obj);
NCBI_XSERIAL_EXPORT CNcbiIstream& operator>> (CNcbiIstream& str, CSerialObject&          obj);
NCBI_XSERIAL_EXPORT CNcbiOstream& operator<< (CNcbiOstream& str, const CConstObjectInfo& obj);
NCBI_XSERIAL_EXPORT CNcbiIstream& operator>> (CNcbiIstream& str, const CObjectInfo&      obj);

NCBI_XSERIAL_EXPORT CNcbiOstream& WriteObject(CNcbiOstream& str, TConstObjectPtr ptr, TTypeInfo info);
NCBI_XSERIAL_EXPORT CNcbiIstream& ReadObject( CNcbiIstream& str, TObjectPtr      ptr, TTypeInfo info);


END_NCBI_SCOPE

// these methods must be defined in root namespace so they have prefix NCBISER

// default functions do nothing
template<class CInfo>
inline
void NCBISERSetPreRead(const void* /*object*/, CInfo* /*info*/)
{
}

template<class CInfo>
inline
void NCBISERSetPostRead(const void* /*object*/, CInfo* /*info*/)
{
}

template<class CInfo>
inline
void NCBISERSetPreWrite(const void* /*object*/, CInfo* /*info*/)
{
}

template<class CInfo>
inline
void NCBISERSetPostWrite(const void* /*object*/, CInfo* /*info*/)
{
}

template<class CInfo>
inline
void NCBISERSetGlobalReadMemberHook(const void* /*object*/, CInfo* /*info*/)
{
}

template<class CInfo>
inline
void NCBISERSetGlobalReadVariantHook(const void* /*object*/, CInfo* /*info*/)
{
}

// define for declaring specific function
#define NCBISER_HAVE_PRE_READ(Class) \
template<class CInfo> \
inline \
void NCBISERSetPreRead(const Class* /*object*/, CInfo* info) \
{ \
    NCBI_NS_NCBI::SetPreRead \
        (info, &NCBI_NS_NCBI::CClassPrePostReadWrite<Class>::PreRead);\
}

#define NCBISER_HAVE_POST_READ(Class) \
template<class CInfo> \
inline \
void NCBISERSetPostRead(const Class* /*object*/, CInfo* info) \
{ \
    NCBI_NS_NCBI::SetPostRead \
        (info, &NCBI_NS_NCBI::CClassPrePostReadWrite<Class>::PostRead);\
}

#define NCBISER_HAVE_PRE_WRITE(Class) \
template<class CInfo> \
inline \
void NCBISERSetPreWrite(const Class* /*object*/, CInfo* info) \
{ \
    NCBI_NS_NCBI::SetPreWrite \
        (info, &NCBI_NS_NCBI::CClassPrePostReadWrite<Class>::PreWrite);\
}

#define NCBISER_HAVE_POST_WRITE(Class) \
template<class CInfo> \
inline \
void NCBISERSetPostWrite(const Class* /*object*/, CInfo* info) \
{ \
    NCBI_NS_NCBI::SetPostWrite \
        (info, &NCBI_NS_NCBI::CClassPrePostReadWrite<Class>::PostWrite);\
}

#define NCBISER_HAVE_GLOBAL_READ_MEMBER_HOOK(Class, Name, Hook)         \
    template<class CInfo>                                               \
    inline                                                              \
    void NCBISERSetGlobalReadMemberHook(const Class* /*obj*/,           \
                                         CInfo* info)                   \
    {                                                                   \
        NCBI_NS_NCBI::SetGlobalReadMemberHook(info, Name, Hook);        \
    }

#define NCBISER_HAVE_GLOBAL_READ_VARIANT_HOOK(Class, Name, Hook)        \
    template<class CInfo>                                               \
    inline                                                              \
    void NCBISERSetGlobalReadVariantHook(const Class* /*obj*/,          \
                                          CInfo* info)                  \
    {                                                                   \
        NCBI_NS_NCBI::SetGlobalReadVariantHook(info, Name, Hook);       \
    }

// define for declaring specific function
#define DECLARE_INTERNAL_TYPE_INFO() \
    typedef const NCBI_NS_NCBI::CTypeInfo* TTypeInfo; \
    virtual TTypeInfo GetThisTypeInfo(void) const { return GetTypeInfo(); } \
    static  TTypeInfo GetTypeInfo(void)

#define ENUM_METHOD_NAME(EnumName) \
    NCBI_NAME2(GetTypeInfo_enum_,EnumName)
#define DECLARE_ENUM_INFO(EnumName) \
    const NCBI_NS_NCBI::CEnumeratedTypeValues* ENUM_METHOD_NAME(EnumName)(void)
#define DECLARE_INTERNAL_ENUM_INFO(EnumName) \
    static DECLARE_ENUM_INFO(EnumName)

//#define DECLARE_STD_ALIAS_TYPE_INFO() DECLARE_INTERNAL_TYPE_INFO()
#define DECLARE_STD_ALIAS_TYPE_INFO() \
           const NCBI_NS_NCBI::CTypeInfo* GetThisTypeInfo(void) const { return GetTypeInfo(); } \
    static const NCBI_NS_NCBI::CTypeInfo* GetTypeInfo(void)

#if HAVE_NCBI_C

#define ASN_STRUCT_NAME(AsnStructName) NCBI_NAME2(struct_, AsnStructName)
#define ASN_STRUCT_METHOD_NAME(AsnStructName) \
    NCBI_NAME2(GetTypeInfo_struct_,AsnStructName)

#define DECLARE_ASN_TYPE_INFO(AsnStructName) \
    const NCBI_NS_NCBI::CTypeInfo* ASN_STRUCT_METHOD_NAME(AsnStructName)(void)
#define DECLARE_ASN_STRUCT_INFO(AsnStructName) \
    struct ASN_STRUCT_NAME(AsnStructName); \
    DECLARE_ASN_TYPE_INFO(AsnStructName); \
    inline \
    const NCBI_NS_NCBI::CTypeInfo* \
    GetAsnStructTypeInfo(const ASN_STRUCT_NAME(AsnStructName)* ) \
    { \
        return ASN_STRUCT_METHOD_NAME(AsnStructName)(); \
    } \
    struct ASN_STRUCT_NAME(AsnStructName)

#define DECLARE_ASN_CHOICE_INFO(AsnChoiceName) \
    DECLARE_ASN_TYPE_INFO(AsnChoiceName)

#endif

/* @} */

#endif  /* SERIALBASE__HPP */
