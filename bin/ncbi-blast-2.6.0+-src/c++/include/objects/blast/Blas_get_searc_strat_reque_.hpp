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

/// @file Blas_get_searc_strat_reque_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'blast.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_BLAST_BLAS_GET_SEARC_STRAT_REQUE_BASE_HPP
#define OBJECTS_BLAST_BLAS_GET_SEARC_STRAT_REQUE_BASE_HPP

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
/// Fetch the search strategy (i.e.: object used to submit the search)
class NCBI_BLAST_EXPORT CBlast4_get_search_strategy_request_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CBlast4_get_search_strategy_request_Base(void);
    // destructor
    virtual ~CBlast4_get_search_strategy_request_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    // types
    typedef string TRequest_id;

    // getters
    // setters

    /// mandatory
    /// typedef string TRequest_id
    ///  Check whether the Request_id data member has been assigned a value.
    bool IsSetRequest_id(void) const;
    /// Check whether it is safe or not to call GetRequest_id method.
    bool CanGetRequest_id(void) const;
    void ResetRequest_id(void);
    const TRequest_id& GetRequest_id(void) const;
    void SetRequest_id(const TRequest_id& value);
    TRequest_id& SetRequest_id(void);

    /// Reset the whole object
    virtual void Reset(void);


private:
    // Prohibit copy constructor and assignment operator
    CBlast4_get_search_strategy_request_Base(const CBlast4_get_search_strategy_request_Base&);
    CBlast4_get_search_strategy_request_Base& operator=(const CBlast4_get_search_strategy_request_Base&);

    // data
    Uint4 m_set_State[1];
    string m_Request_id;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
bool CBlast4_get_search_strategy_request_Base::IsSetRequest_id(void) const
{
    return ((m_set_State[0] & 0x3) != 0);
}

inline
bool CBlast4_get_search_strategy_request_Base::CanGetRequest_id(void) const
{
    return IsSetRequest_id();
}

inline
const CBlast4_get_search_strategy_request_Base::TRequest_id& CBlast4_get_search_strategy_request_Base::GetRequest_id(void) const
{
    if (!CanGetRequest_id()) {
        ThrowUnassigned(0);
    }
    return m_Request_id;
}

inline
void CBlast4_get_search_strategy_request_Base::SetRequest_id(const CBlast4_get_search_strategy_request_Base::TRequest_id& value)
{
    m_Request_id = value;
    m_set_State[0] |= 0x3;
}

inline
CBlast4_get_search_strategy_request_Base::TRequest_id& CBlast4_get_search_strategy_request_Base::SetRequest_id(void)
{
#ifdef _DEBUG
    if (!IsSetRequest_id()) {
        m_Request_id = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x1;
    return m_Request_id;
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_BLAST_BLAS_GET_SEARC_STRAT_REQUE_BASE_HPP
