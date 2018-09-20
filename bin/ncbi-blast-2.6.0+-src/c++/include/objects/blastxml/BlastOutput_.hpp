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

/// @file BlastOutput_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'blastxml.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_BLASTXML_BLASTOUTPUT_BASE_HPP
#define OBJECTS_BLASTXML_BLASTOUTPUT_BASE_HPP

// standard includes
#include <serial/serialbase.hpp>

// generated includes
#include <list>
#include <string>

BEGIN_NCBI_SCOPE

#ifndef BEGIN_objects_SCOPE
#  define BEGIN_objects_SCOPE BEGIN_SCOPE(objects)
#  define END_objects_SCOPE END_SCOPE(objects)
#endif
BEGIN_objects_SCOPE // namespace ncbi::objects::


// forward declarations
class CIteration;
class CParameters;
class CStatistics;


// generated classes

/////////////////////////////////////////////////////////////////////////////
class NCBI_BLASTXML_EXPORT CBlastOutput_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CBlastOutput_Base(void);
    // destructor
    virtual ~CBlastOutput_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    // types
    typedef string TProgram;
    typedef string TVersion;
    typedef string TReference;
    typedef string TDb;
    typedef string TQuery_ID;
    typedef string TQuery_def;
    typedef int TQuery_len;
    typedef string TQuery_seq;
    typedef CParameters TParam;
    typedef list< CRef< CIteration > > TIterations;
    typedef CStatistics TMbstat;

    // getters
    // setters

    /// BLAST program: blastp, tblastx etc.
    /// mandatory
    /// typedef string TProgram
    ///  Check whether the Program data member has been assigned a value.
    bool IsSetProgram(void) const;
    /// Check whether it is safe or not to call GetProgram method.
    bool CanGetProgram(void) const;
    void ResetProgram(void);
    const TProgram& GetProgram(void) const;
    void SetProgram(const TProgram& value);
    TProgram& SetProgram(void);

    /// Program version 
    /// mandatory
    /// typedef string TVersion
    ///  Check whether the Version data member has been assigned a value.
    bool IsSetVersion(void) const;
    /// Check whether it is safe or not to call GetVersion method.
    bool CanGetVersion(void) const;
    void ResetVersion(void);
    const TVersion& GetVersion(void) const;
    void SetVersion(const TVersion& value);
    TVersion& SetVersion(void);

    /// Steven, David, Tom and others
    /// mandatory
    /// typedef string TReference
    ///  Check whether the Reference data member has been assigned a value.
    bool IsSetReference(void) const;
    /// Check whether it is safe or not to call GetReference method.
    bool CanGetReference(void) const;
    void ResetReference(void);
    const TReference& GetReference(void) const;
    void SetReference(const TReference& value);
    TReference& SetReference(void);

    /// BLAST Database name
    /// mandatory
    /// typedef string TDb
    ///  Check whether the Db data member has been assigned a value.
    bool IsSetDb(void) const;
    /// Check whether it is safe or not to call GetDb method.
    bool CanGetDb(void) const;
    void ResetDb(void);
    const TDb& GetDb(void) const;
    void SetDb(const TDb& value);
    TDb& SetDb(void);

    /// SeqId of query
    /// mandatory
    /// typedef string TQuery_ID
    ///  Check whether the Query_ID data member has been assigned a value.
    bool IsSetQuery_ID(void) const;
    /// Check whether it is safe or not to call GetQuery_ID method.
    bool CanGetQuery_ID(void) const;
    void ResetQuery_ID(void);
    const TQuery_ID& GetQuery_ID(void) const;
    void SetQuery_ID(const TQuery_ID& value);
    TQuery_ID& SetQuery_ID(void);

    /// Definition line of query
    /// mandatory
    /// typedef string TQuery_def
    ///  Check whether the Query_def data member has been assigned a value.
    bool IsSetQuery_def(void) const;
    /// Check whether it is safe or not to call GetQuery_def method.
    bool CanGetQuery_def(void) const;
    void ResetQuery_def(void);
    const TQuery_def& GetQuery_def(void) const;
    void SetQuery_def(const TQuery_def& value);
    TQuery_def& SetQuery_def(void);

    /// length of query sequence
    /// mandatory
    /// typedef int TQuery_len
    ///  Check whether the Query_len data member has been assigned a value.
    bool IsSetQuery_len(void) const;
    /// Check whether it is safe or not to call GetQuery_len method.
    bool CanGetQuery_len(void) const;
    void ResetQuery_len(void);
    TQuery_len GetQuery_len(void) const;
    void SetQuery_len(TQuery_len value);
    TQuery_len& SetQuery_len(void);

    /// query sequence itself
    /// optional
    /// typedef string TQuery_seq
    ///  Check whether the Query_seq data member has been assigned a value.
    bool IsSetQuery_seq(void) const;
    /// Check whether it is safe or not to call GetQuery_seq method.
    bool CanGetQuery_seq(void) const;
    void ResetQuery_seq(void);
    const TQuery_seq& GetQuery_seq(void) const;
    void SetQuery_seq(const TQuery_seq& value);
    TQuery_seq& SetQuery_seq(void);

    /// search parameters
    /// mandatory
    /// typedef CParameters TParam
    ///  Check whether the Param data member has been assigned a value.
    bool IsSetParam(void) const;
    /// Check whether it is safe or not to call GetParam method.
    bool CanGetParam(void) const;
    void ResetParam(void);
    const TParam& GetParam(void) const;
    void SetParam(TParam& value);
    TParam& SetParam(void);

    /// mandatory
    /// typedef list< CRef< CIteration > > TIterations
    ///  Check whether the Iterations data member has been assigned a value.
    bool IsSetIterations(void) const;
    /// Check whether it is safe or not to call GetIterations method.
    bool CanGetIterations(void) const;
    void ResetIterations(void);
    const TIterations& GetIterations(void) const;
    TIterations& SetIterations(void);

    /// Mega BLAST search statistics
    /// optional
    /// typedef CStatistics TMbstat
    ///  Check whether the Mbstat data member has been assigned a value.
    bool IsSetMbstat(void) const;
    /// Check whether it is safe or not to call GetMbstat method.
    bool CanGetMbstat(void) const;
    void ResetMbstat(void);
    const TMbstat& GetMbstat(void) const;
    void SetMbstat(TMbstat& value);
    TMbstat& SetMbstat(void);

    /// Reset the whole object
    virtual void Reset(void);


private:
    // Prohibit copy constructor and assignment operator
    CBlastOutput_Base(const CBlastOutput_Base&);
    CBlastOutput_Base& operator=(const CBlastOutput_Base&);

    // data
    Uint4 m_set_State[1];
    string m_Program;
    string m_Version;
    string m_Reference;
    string m_Db;
    string m_Query_ID;
    string m_Query_def;
    int m_Query_len;
    string m_Query_seq;
    CRef< TParam > m_Param;
    list< CRef< CIteration > > m_Iterations;
    CRef< TMbstat > m_Mbstat;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
bool CBlastOutput_Base::IsSetProgram(void) const
{
    return ((m_set_State[0] & 0x3) != 0);
}

inline
bool CBlastOutput_Base::CanGetProgram(void) const
{
    return IsSetProgram();
}

inline
const CBlastOutput_Base::TProgram& CBlastOutput_Base::GetProgram(void) const
{
    if (!CanGetProgram()) {
        ThrowUnassigned(0);
    }
    return m_Program;
}

inline
void CBlastOutput_Base::SetProgram(const CBlastOutput_Base::TProgram& value)
{
    m_Program = value;
    m_set_State[0] |= 0x3;
}

inline
CBlastOutput_Base::TProgram& CBlastOutput_Base::SetProgram(void)
{
#ifdef _DEBUG
    if (!IsSetProgram()) {
        m_Program = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x1;
    return m_Program;
}

inline
bool CBlastOutput_Base::IsSetVersion(void) const
{
    return ((m_set_State[0] & 0xc) != 0);
}

inline
bool CBlastOutput_Base::CanGetVersion(void) const
{
    return IsSetVersion();
}

inline
const CBlastOutput_Base::TVersion& CBlastOutput_Base::GetVersion(void) const
{
    if (!CanGetVersion()) {
        ThrowUnassigned(1);
    }
    return m_Version;
}

inline
void CBlastOutput_Base::SetVersion(const CBlastOutput_Base::TVersion& value)
{
    m_Version = value;
    m_set_State[0] |= 0xc;
}

inline
CBlastOutput_Base::TVersion& CBlastOutput_Base::SetVersion(void)
{
#ifdef _DEBUG
    if (!IsSetVersion()) {
        m_Version = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x4;
    return m_Version;
}

inline
bool CBlastOutput_Base::IsSetReference(void) const
{
    return ((m_set_State[0] & 0x30) != 0);
}

inline
bool CBlastOutput_Base::CanGetReference(void) const
{
    return IsSetReference();
}

inline
const CBlastOutput_Base::TReference& CBlastOutput_Base::GetReference(void) const
{
    if (!CanGetReference()) {
        ThrowUnassigned(2);
    }
    return m_Reference;
}

inline
void CBlastOutput_Base::SetReference(const CBlastOutput_Base::TReference& value)
{
    m_Reference = value;
    m_set_State[0] |= 0x30;
}

inline
CBlastOutput_Base::TReference& CBlastOutput_Base::SetReference(void)
{
#ifdef _DEBUG
    if (!IsSetReference()) {
        m_Reference = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x10;
    return m_Reference;
}

inline
bool CBlastOutput_Base::IsSetDb(void) const
{
    return ((m_set_State[0] & 0xc0) != 0);
}

inline
bool CBlastOutput_Base::CanGetDb(void) const
{
    return IsSetDb();
}

inline
const CBlastOutput_Base::TDb& CBlastOutput_Base::GetDb(void) const
{
    if (!CanGetDb()) {
        ThrowUnassigned(3);
    }
    return m_Db;
}

inline
void CBlastOutput_Base::SetDb(const CBlastOutput_Base::TDb& value)
{
    m_Db = value;
    m_set_State[0] |= 0xc0;
}

inline
CBlastOutput_Base::TDb& CBlastOutput_Base::SetDb(void)
{
#ifdef _DEBUG
    if (!IsSetDb()) {
        m_Db = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x40;
    return m_Db;
}

inline
bool CBlastOutput_Base::IsSetQuery_ID(void) const
{
    return ((m_set_State[0] & 0x300) != 0);
}

inline
bool CBlastOutput_Base::CanGetQuery_ID(void) const
{
    return IsSetQuery_ID();
}

inline
const CBlastOutput_Base::TQuery_ID& CBlastOutput_Base::GetQuery_ID(void) const
{
    if (!CanGetQuery_ID()) {
        ThrowUnassigned(4);
    }
    return m_Query_ID;
}

inline
void CBlastOutput_Base::SetQuery_ID(const CBlastOutput_Base::TQuery_ID& value)
{
    m_Query_ID = value;
    m_set_State[0] |= 0x300;
}

inline
CBlastOutput_Base::TQuery_ID& CBlastOutput_Base::SetQuery_ID(void)
{
#ifdef _DEBUG
    if (!IsSetQuery_ID()) {
        m_Query_ID = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x100;
    return m_Query_ID;
}

inline
bool CBlastOutput_Base::IsSetQuery_def(void) const
{
    return ((m_set_State[0] & 0xc00) != 0);
}

inline
bool CBlastOutput_Base::CanGetQuery_def(void) const
{
    return IsSetQuery_def();
}

inline
const CBlastOutput_Base::TQuery_def& CBlastOutput_Base::GetQuery_def(void) const
{
    if (!CanGetQuery_def()) {
        ThrowUnassigned(5);
    }
    return m_Query_def;
}

inline
void CBlastOutput_Base::SetQuery_def(const CBlastOutput_Base::TQuery_def& value)
{
    m_Query_def = value;
    m_set_State[0] |= 0xc00;
}

inline
CBlastOutput_Base::TQuery_def& CBlastOutput_Base::SetQuery_def(void)
{
#ifdef _DEBUG
    if (!IsSetQuery_def()) {
        m_Query_def = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x400;
    return m_Query_def;
}

inline
bool CBlastOutput_Base::IsSetQuery_len(void) const
{
    return ((m_set_State[0] & 0x3000) != 0);
}

inline
bool CBlastOutput_Base::CanGetQuery_len(void) const
{
    return IsSetQuery_len();
}

inline
void CBlastOutput_Base::ResetQuery_len(void)
{
    m_Query_len = 0;
    m_set_State[0] &= ~0x3000;
}

inline
CBlastOutput_Base::TQuery_len CBlastOutput_Base::GetQuery_len(void) const
{
    if (!CanGetQuery_len()) {
        ThrowUnassigned(6);
    }
    return m_Query_len;
}

inline
void CBlastOutput_Base::SetQuery_len(CBlastOutput_Base::TQuery_len value)
{
    m_Query_len = value;
    m_set_State[0] |= 0x3000;
}

inline
CBlastOutput_Base::TQuery_len& CBlastOutput_Base::SetQuery_len(void)
{
#ifdef _DEBUG
    if (!IsSetQuery_len()) {
        memset(&m_Query_len,UnassignedByte(),sizeof(m_Query_len));
    }
#endif
    m_set_State[0] |= 0x1000;
    return m_Query_len;
}

inline
bool CBlastOutput_Base::IsSetQuery_seq(void) const
{
    return ((m_set_State[0] & 0xc000) != 0);
}

inline
bool CBlastOutput_Base::CanGetQuery_seq(void) const
{
    return IsSetQuery_seq();
}

inline
const CBlastOutput_Base::TQuery_seq& CBlastOutput_Base::GetQuery_seq(void) const
{
    if (!CanGetQuery_seq()) {
        ThrowUnassigned(7);
    }
    return m_Query_seq;
}

inline
void CBlastOutput_Base::SetQuery_seq(const CBlastOutput_Base::TQuery_seq& value)
{
    m_Query_seq = value;
    m_set_State[0] |= 0xc000;
}

inline
CBlastOutput_Base::TQuery_seq& CBlastOutput_Base::SetQuery_seq(void)
{
#ifdef _DEBUG
    if (!IsSetQuery_seq()) {
        m_Query_seq = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x4000;
    return m_Query_seq;
}

inline
bool CBlastOutput_Base::IsSetParam(void) const
{
    return m_Param.NotEmpty();
}

inline
bool CBlastOutput_Base::CanGetParam(void) const
{
    return true;
}

inline
const CBlastOutput_Base::TParam& CBlastOutput_Base::GetParam(void) const
{
    if ( !m_Param ) {
        const_cast<CBlastOutput_Base*>(this)->ResetParam();
    }
    return (*m_Param);
}

inline
CBlastOutput_Base::TParam& CBlastOutput_Base::SetParam(void)
{
    if ( !m_Param ) {
        ResetParam();
    }
    return (*m_Param);
}

inline
bool CBlastOutput_Base::IsSetIterations(void) const
{
    return ((m_set_State[0] & 0xc0000) != 0);
}

inline
bool CBlastOutput_Base::CanGetIterations(void) const
{
    return true;
}

inline
const CBlastOutput_Base::TIterations& CBlastOutput_Base::GetIterations(void) const
{
    return m_Iterations;
}

inline
CBlastOutput_Base::TIterations& CBlastOutput_Base::SetIterations(void)
{
    m_set_State[0] |= 0x40000;
    return m_Iterations;
}

inline
bool CBlastOutput_Base::IsSetMbstat(void) const
{
    return m_Mbstat.NotEmpty();
}

inline
bool CBlastOutput_Base::CanGetMbstat(void) const
{
    return IsSetMbstat();
}

inline
const CBlastOutput_Base::TMbstat& CBlastOutput_Base::GetMbstat(void) const
{
    if (!CanGetMbstat()) {
        ThrowUnassigned(10);
    }
    return (*m_Mbstat);
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_BLASTXML_BLASTOUTPUT_BASE_HPP