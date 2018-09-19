/* $Id$
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
 */

/// @file GCClient_ValidateChrTypeLo_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'gencoll_client.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_GENOMECOLL_GCCLIENT_VALIDATECHRTYPELO_BASE_HPP
#define OBJECTS_GENOMECOLL_GCCLIENT_VALIDATECHRTYPELO_BASE_HPP

// standard includes
#include <serial/serialbase.hpp>

// generated includes
#include <string>

BEGIN_NCBI_SCOPE

#ifndef BEGIN_objects_SCOPE
#  define BEGIN_objects_SCOPE BEGIN_SCOPE(objects)
#  define END_objects_SCOPE END_SCOPE(objects)
#endif
BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

/////////////////////////////////////////////////////////////////////////////
class CGCClient_ValidateChrTypeLocResponse_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CGCClient_ValidateChrTypeLocResponse_Base(void);
    // destructor
    virtual ~CGCClient_ValidateChrTypeLocResponse_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    // types
    typedef string TResult;

    // getters
    // setters

    /// Result of the Type Location validate request
    /// mandatory
    /// typedef string TResult
    ///  Check whether the Result data member has been assigned a value.
    bool IsSetResult(void) const;
    /// Check whether it is safe or not to call GetResult method.
    bool CanGetResult(void) const;
    void ResetResult(void);
    const TResult& GetResult(void) const;
    void SetResult(const TResult& value);
    TResult& SetResult(void);

    /// Reset the whole object
    virtual void Reset(void);


private:
    // Prohibit copy constructor and assignment operator
    CGCClient_ValidateChrTypeLocResponse_Base(const CGCClient_ValidateChrTypeLocResponse_Base&);
    CGCClient_ValidateChrTypeLocResponse_Base& operator=(const CGCClient_ValidateChrTypeLocResponse_Base&);

    // data
    Uint4 m_set_State[1];
    string m_Result;
};
/////////////////////////////////////////////////////////////////////////////
class CGCClient_ValidateChrTypeLocRequest_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CGCClient_ValidateChrTypeLocRequest_Base(void);
    // destructor
    virtual ~CGCClient_ValidateChrTypeLocRequest_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    // types
    typedef string TType;
    typedef string TLocation;

    // getters
    // setters

    /// Validate the Type Location in the request
    /// mandatory
    /// typedef string TType
    ///  Check whether the Type data member has been assigned a value.
    bool IsSetType(void) const;
    /// Check whether it is safe or not to call GetType method.
    bool CanGetType(void) const;
    void ResetType(void);
    const TType& GetType(void) const;
    void SetType(const TType& value);
    TType& SetType(void);

    /// mandatory
    /// typedef string TLocation
    ///  Check whether the Location data member has been assigned a value.
    bool IsSetLocation(void) const;
    /// Check whether it is safe or not to call GetLocation method.
    bool CanGetLocation(void) const;
    void ResetLocation(void);
    const TLocation& GetLocation(void) const;
    void SetLocation(const TLocation& value);
    TLocation& SetLocation(void);

    /// Reset the whole object
    virtual void Reset(void);


private:
    // Prohibit copy constructor and assignment operator
    CGCClient_ValidateChrTypeLocRequest_Base(const CGCClient_ValidateChrTypeLocRequest_Base&);
    CGCClient_ValidateChrTypeLocRequest_Base& operator=(const CGCClient_ValidateChrTypeLocRequest_Base&);

    // data
    Uint4 m_set_State[1];
    string m_Type;
    string m_Location;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
bool CGCClient_ValidateChrTypeLocResponse_Base::IsSetResult(void) const
{
    return ((m_set_State[0] & 0x3) != 0);
}

inline
bool CGCClient_ValidateChrTypeLocResponse_Base::CanGetResult(void) const
{
    return IsSetResult();
}

inline
const CGCClient_ValidateChrTypeLocResponse_Base::TResult& CGCClient_ValidateChrTypeLocResponse_Base::GetResult(void) const
{
    if (!CanGetResult()) {
        ThrowUnassigned(0);
    }
    return m_Result;
}

inline
void CGCClient_ValidateChrTypeLocResponse_Base::SetResult(const CGCClient_ValidateChrTypeLocResponse_Base::TResult& value)
{
    m_Result = value;
    m_set_State[0] |= 0x3;
}

inline
CGCClient_ValidateChrTypeLocResponse_Base::TResult& CGCClient_ValidateChrTypeLocResponse_Base::SetResult(void)
{
#ifdef _DEBUG
    if (!IsSetResult()) {
        m_Result = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x1;
    return m_Result;
}

inline
bool CGCClient_ValidateChrTypeLocRequest_Base::IsSetType(void) const
{
    return ((m_set_State[0] & 0x3) != 0);
}

inline
bool CGCClient_ValidateChrTypeLocRequest_Base::CanGetType(void) const
{
    return IsSetType();
}

inline
const CGCClient_ValidateChrTypeLocRequest_Base::TType& CGCClient_ValidateChrTypeLocRequest_Base::GetType(void) const
{
    if (!CanGetType()) {
        ThrowUnassigned(0);
    }
    return m_Type;
}

inline
void CGCClient_ValidateChrTypeLocRequest_Base::SetType(const CGCClient_ValidateChrTypeLocRequest_Base::TType& value)
{
    m_Type = value;
    m_set_State[0] |= 0x3;
}

inline
CGCClient_ValidateChrTypeLocRequest_Base::TType& CGCClient_ValidateChrTypeLocRequest_Base::SetType(void)
{
#ifdef _DEBUG
    if (!IsSetType()) {
        m_Type = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x1;
    return m_Type;
}

inline
bool CGCClient_ValidateChrTypeLocRequest_Base::IsSetLocation(void) const
{
    return ((m_set_State[0] & 0xc) != 0);
}

inline
bool CGCClient_ValidateChrTypeLocRequest_Base::CanGetLocation(void) const
{
    return IsSetLocation();
}

inline
const CGCClient_ValidateChrTypeLocRequest_Base::TLocation& CGCClient_ValidateChrTypeLocRequest_Base::GetLocation(void) const
{
    if (!CanGetLocation()) {
        ThrowUnassigned(1);
    }
    return m_Location;
}

inline
void CGCClient_ValidateChrTypeLocRequest_Base::SetLocation(const CGCClient_ValidateChrTypeLocRequest_Base::TLocation& value)
{
    m_Location = value;
    m_set_State[0] |= 0xc;
}

inline
CGCClient_ValidateChrTypeLocRequest_Base::TLocation& CGCClient_ValidateChrTypeLocRequest_Base::SetLocation(void)
{
#ifdef _DEBUG
    if (!IsSetLocation()) {
        m_Location = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x4;
    return m_Location;
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_GENOMECOLL_GCCLIENT_VALIDATECHRTYPELO_BASE_HPP
