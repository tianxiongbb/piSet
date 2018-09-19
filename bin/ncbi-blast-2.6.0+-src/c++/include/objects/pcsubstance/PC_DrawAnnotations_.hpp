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

/// @file PC_DrawAnnotations_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'pcsubstance.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_PCSUBSTANCE_PC_DRAWANNOTATIONS_BASE_HPP
#define OBJECTS_PCSUBSTANCE_PC_DRAWANNOTATIONS_BASE_HPP

// standard includes
#include <serial/serialbase.hpp>

// generated includes
#include <vector>
#include <objects/pcsubstance/PC_BondAnnotation.hpp>

BEGIN_NCBI_SCOPE

#ifndef BEGIN_objects_SCOPE
#  define BEGIN_objects_SCOPE BEGIN_SCOPE(objects)
#  define END_objects_SCOPE END_SCOPE(objects)
#endif
BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

/////////////////////////////////////////////////////////////////////////////
/// Drawing Annotations (in Parallel Arrays)
///    [Note: A pair of atoms can have multiple annotations]
class NCBI_PCSUBSTANCE_EXPORT CPC_DrawAnnotations_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CPC_DrawAnnotations_Base(void);
    // destructor
    virtual ~CPC_DrawAnnotations_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    // types
    typedef vector< int > TAnnotation;
    typedef vector< int > TAid1;
    typedef vector< int > TAid2;

    // getters
    // setters

    ///  [Note: Parallel Arrays must be kept Synchronized]
    /// Bond Annotations (vector)
    /// mandatory
    /// typedef vector< int > TAnnotation
    ///  Check whether the Annotation data member has been assigned a value.
    bool IsSetAnnotation(void) const;
    /// Check whether it is safe or not to call GetAnnotation method.
    bool CanGetAnnotation(void) const;
    void ResetAnnotation(void);
    const TAnnotation& GetAnnotation(void) const;
    TAnnotation& SetAnnotation(void);

    /// Atom1 Identifier (vector)
    ///   Note: Atom ID's must be greater than "0"
    /// mandatory
    /// typedef vector< int > TAid1
    ///  Check whether the Aid1 data member has been assigned a value.
    bool IsSetAid1(void) const;
    /// Check whether it is safe or not to call GetAid1 method.
    bool CanGetAid1(void) const;
    void ResetAid1(void);
    const TAid1& GetAid1(void) const;
    TAid1& SetAid1(void);

    /// Atom2 Identifier (vector)
    ///   Note: Atom ID's must be greater than "0"
    /// mandatory
    /// typedef vector< int > TAid2
    ///  Check whether the Aid2 data member has been assigned a value.
    bool IsSetAid2(void) const;
    /// Check whether it is safe or not to call GetAid2 method.
    bool CanGetAid2(void) const;
    void ResetAid2(void);
    const TAid2& GetAid2(void) const;
    TAid2& SetAid2(void);

    /// Reset the whole object
    virtual void Reset(void);


private:
    // Prohibit copy constructor and assignment operator
    CPC_DrawAnnotations_Base(const CPC_DrawAnnotations_Base&);
    CPC_DrawAnnotations_Base& operator=(const CPC_DrawAnnotations_Base&);

    // data
    Uint4 m_set_State[1];
    vector< int > m_Annotation;
    vector< int > m_Aid1;
    vector< int > m_Aid2;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
bool CPC_DrawAnnotations_Base::IsSetAnnotation(void) const
{
    return ((m_set_State[0] & 0x3) != 0);
}

inline
bool CPC_DrawAnnotations_Base::CanGetAnnotation(void) const
{
    return true;
}

inline
const CPC_DrawAnnotations_Base::TAnnotation& CPC_DrawAnnotations_Base::GetAnnotation(void) const
{
    return m_Annotation;
}

inline
CPC_DrawAnnotations_Base::TAnnotation& CPC_DrawAnnotations_Base::SetAnnotation(void)
{
    m_set_State[0] |= 0x1;
    return m_Annotation;
}

inline
bool CPC_DrawAnnotations_Base::IsSetAid1(void) const
{
    return ((m_set_State[0] & 0xc) != 0);
}

inline
bool CPC_DrawAnnotations_Base::CanGetAid1(void) const
{
    return true;
}

inline
const CPC_DrawAnnotations_Base::TAid1& CPC_DrawAnnotations_Base::GetAid1(void) const
{
    return m_Aid1;
}

inline
CPC_DrawAnnotations_Base::TAid1& CPC_DrawAnnotations_Base::SetAid1(void)
{
    m_set_State[0] |= 0x4;
    return m_Aid1;
}

inline
bool CPC_DrawAnnotations_Base::IsSetAid2(void) const
{
    return ((m_set_State[0] & 0x30) != 0);
}

inline
bool CPC_DrawAnnotations_Base::CanGetAid2(void) const
{
    return true;
}

inline
const CPC_DrawAnnotations_Base::TAid2& CPC_DrawAnnotations_Base::GetAid2(void) const
{
    return m_Aid2;
}

inline
CPC_DrawAnnotations_Base::TAid2& CPC_DrawAnnotations_Base::SetAid2(void)
{
    m_set_State[0] |= 0x10;
    return m_Aid2;
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_PCSUBSTANCE_PC_DRAWANNOTATIONS_BASE_HPP
