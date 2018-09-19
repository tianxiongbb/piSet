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

/// @file Cit_jour_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'biblio.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_BIBLIO_CIT_JOUR_BASE_HPP
#define OBJECTS_BIBLIO_CIT_JOUR_BASE_HPP

// standard includes
#include <serial/serialbase.hpp>
BEGIN_NCBI_SCOPE

#ifndef BEGIN_objects_SCOPE
#  define BEGIN_objects_SCOPE BEGIN_SCOPE(objects)
#  define END_objects_SCOPE END_SCOPE(objects)
#endif
BEGIN_objects_SCOPE // namespace ncbi::objects::


// forward declarations
class CImprint;
class CTitle;


// generated classes

/////////////////////////////////////////////////////////////////////////////
/// Journal citation
class NCBI_BIBLIO_EXPORT CCit_jour_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CCit_jour_Base(void);
    // destructor
    virtual ~CCit_jour_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    // types
    typedef CTitle TTitle;
    typedef CImprint TImp;

    // getters
    // setters

    /// title of journal
    /// mandatory
    /// typedef CTitle TTitle
    ///  Check whether the Title data member has been assigned a value.
    bool IsSetTitle(void) const;
    /// Check whether it is safe or not to call GetTitle method.
    bool CanGetTitle(void) const;
    void ResetTitle(void);
    const TTitle& GetTitle(void) const;
    void SetTitle(TTitle& value);
    TTitle& SetTitle(void);

    /// mandatory
    /// typedef CImprint TImp
    ///  Check whether the Imp data member has been assigned a value.
    bool IsSetImp(void) const;
    /// Check whether it is safe or not to call GetImp method.
    bool CanGetImp(void) const;
    void ResetImp(void);
    const TImp& GetImp(void) const;
    void SetImp(TImp& value);
    TImp& SetImp(void);

    /// Reset the whole object
    virtual void Reset(void);


private:
    // Prohibit copy constructor and assignment operator
    CCit_jour_Base(const CCit_jour_Base&);
    CCit_jour_Base& operator=(const CCit_jour_Base&);

    // data
    Uint4 m_set_State[1];
    CRef< TTitle > m_Title;
    CRef< TImp > m_Imp;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
bool CCit_jour_Base::IsSetTitle(void) const
{
    return m_Title.NotEmpty();
}

inline
bool CCit_jour_Base::CanGetTitle(void) const
{
    return true;
}

inline
const CCit_jour_Base::TTitle& CCit_jour_Base::GetTitle(void) const
{
    if ( !m_Title ) {
        const_cast<CCit_jour_Base*>(this)->ResetTitle();
    }
    return (*m_Title);
}

inline
CCit_jour_Base::TTitle& CCit_jour_Base::SetTitle(void)
{
    if ( !m_Title ) {
        ResetTitle();
    }
    return (*m_Title);
}

inline
bool CCit_jour_Base::IsSetImp(void) const
{
    return m_Imp.NotEmpty();
}

inline
bool CCit_jour_Base::CanGetImp(void) const
{
    return true;
}

inline
const CCit_jour_Base::TImp& CCit_jour_Base::GetImp(void) const
{
    if ( !m_Imp ) {
        const_cast<CCit_jour_Base*>(this)->ResetImp();
    }
    return (*m_Imp);
}

inline
CCit_jour_Base::TImp& CCit_jour_Base::SetImp(void)
{
    if ( !m_Imp ) {
        ResetImp();
    }
    return (*m_Imp);
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_BIBLIO_CIT_JOUR_BASE_HPP
