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

/// @file Cn3d_style_dictionary_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'cn3d.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_CN3D_CN3D_STYLE_DICTIONARY_BASE_HPP
#define OBJECTS_CN3D_CN3D_STYLE_DICTIONARY_BASE_HPP

// standard includes
#include <serial/serialbase.hpp>

// generated includes
#include <list>

BEGIN_NCBI_SCOPE

#ifndef BEGIN_objects_SCOPE
#  define BEGIN_objects_SCOPE BEGIN_SCOPE(objects)
#  define END_objects_SCOPE END_SCOPE(objects)
#endif
BEGIN_objects_SCOPE // namespace ncbi::objects::


// forward declarations
class CCn3d_style_settings;
class CCn3d_style_table_item;


// generated classes

/////////////////////////////////////////////////////////////////////////////
/// the global settings, and a lookup table of styles for user annotations.
class NCBI_CN3D_EXPORT CCn3d_style_dictionary_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CCn3d_style_dictionary_Base(void);
    // destructor
    virtual ~CCn3d_style_dictionary_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    // types
    typedef CCn3d_style_settings TGlobal_style;
    typedef list< CRef< CCn3d_style_table_item > > TStyle_table;

    // getters
    // setters

    /// mandatory
    /// typedef CCn3d_style_settings TGlobal_style
    ///  Check whether the Global_style data member has been assigned a value.
    bool IsSetGlobal_style(void) const;
    /// Check whether it is safe or not to call GetGlobal_style method.
    bool CanGetGlobal_style(void) const;
    void ResetGlobal_style(void);
    const TGlobal_style& GetGlobal_style(void) const;
    void SetGlobal_style(TGlobal_style& value);
    TGlobal_style& SetGlobal_style(void);

    /// optional
    /// typedef list< CRef< CCn3d_style_table_item > > TStyle_table
    ///  Check whether the Style_table data member has been assigned a value.
    bool IsSetStyle_table(void) const;
    /// Check whether it is safe or not to call GetStyle_table method.
    bool CanGetStyle_table(void) const;
    void ResetStyle_table(void);
    const TStyle_table& GetStyle_table(void) const;
    TStyle_table& SetStyle_table(void);

    /// Reset the whole object
    virtual void Reset(void);


private:
    // Prohibit copy constructor and assignment operator
    CCn3d_style_dictionary_Base(const CCn3d_style_dictionary_Base&);
    CCn3d_style_dictionary_Base& operator=(const CCn3d_style_dictionary_Base&);

    // data
    Uint4 m_set_State[1];
    CRef< TGlobal_style > m_Global_style;
    list< CRef< CCn3d_style_table_item > > m_Style_table;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
bool CCn3d_style_dictionary_Base::IsSetGlobal_style(void) const
{
    return m_Global_style.NotEmpty();
}

inline
bool CCn3d_style_dictionary_Base::CanGetGlobal_style(void) const
{
    return true;
}

inline
const CCn3d_style_dictionary_Base::TGlobal_style& CCn3d_style_dictionary_Base::GetGlobal_style(void) const
{
    if ( !m_Global_style ) {
        const_cast<CCn3d_style_dictionary_Base*>(this)->ResetGlobal_style();
    }
    return (*m_Global_style);
}

inline
CCn3d_style_dictionary_Base::TGlobal_style& CCn3d_style_dictionary_Base::SetGlobal_style(void)
{
    if ( !m_Global_style ) {
        ResetGlobal_style();
    }
    return (*m_Global_style);
}

inline
bool CCn3d_style_dictionary_Base::IsSetStyle_table(void) const
{
    return ((m_set_State[0] & 0xc) != 0);
}

inline
bool CCn3d_style_dictionary_Base::CanGetStyle_table(void) const
{
    return true;
}

inline
const CCn3d_style_dictionary_Base::TStyle_table& CCn3d_style_dictionary_Base::GetStyle_table(void) const
{
    return m_Style_table;
}

inline
CCn3d_style_dictionary_Base::TStyle_table& CCn3d_style_dictionary_Base::SetStyle_table(void)
{
    m_set_State[0] |= 0x4;
    return m_Style_table;
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_CN3D_CN3D_STYLE_DICTIONARY_BASE_HPP
