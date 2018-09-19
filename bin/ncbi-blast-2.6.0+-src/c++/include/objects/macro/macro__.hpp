#include <objects/macro/AECRParse_action.hpp>
#include <objects/macro/AECR_action.hpp>
#include <objects/macro/Action_choice.hpp>
#include <objects/macro/Add_descriptor_list_action.hpp>
#include <objects/macro/Add_file_action.hpp>
#include <objects/macro/Adjus_featu_for_gaps_actio.hpp>
#include <objects/macro/Apply_action.hpp>
#include <objects/macro/Apply_feature_action.hpp>
#include <objects/macro/Apply_table_action.hpp>
#include <objects/macro/Apply_table_extra_data.hpp>
#include <objects/macro/Author_fix_action.hpp>
#include <objects/macro/Author_fix_type.hpp>
#include <objects/macro/Autod_misc_feat_parse_rule.hpp>
#include <objects/macro/Autodef_action.hpp>
#include <objects/macro/Autodef_list_type.hpp>
#include <objects/macro/Autofix_action.hpp>
#include <objects/macro/Bond_type.hpp>
#include <objects/macro/CDSGen_featur_type_constra.hpp>
#include <objects/macro/CDSGenePr_constraint_field.hpp>
#include <objects/macro/CDSGenePr_pseudo_constrain.hpp>
#include <objects/macro/CDSGenePro_qual_constraint.hpp>
#include <objects/macro/CDSGeneProt_field.hpp>
#include <objects/macro/CDSGeneProt_field_pair.hpp>
#include <objects/macro/Cap_change.hpp>
#include <objects/macro/Completedness_type.hpp>
#include <objects/macro/Constraint_choice.hpp>
#include <objects/macro/Constraint_choice_set.hpp>
#include <objects/macro/Conver_feature_dst_options.hpp>
#include <objects/macro/Conver_feature_src_options.hpp>
#include <objects/macro/Convert_action.hpp>
#include <objects/macro/Convert_feature_action.hpp>
#include <objects/macro/Convert_from_CDS_options.hpp>
#include <objects/macro/Convert_location_type.hpp>
#include <objects/macro/Copy_action.hpp>
#include <objects/macro/Create_TSA_ids_action.hpp>
#include <objects/macro/Create_TSA_ids_src.hpp>
#include <objects/macro/DBLink_field_pair.hpp>
#include <objects/macro/DBLink_field_type.hpp>
#include <objects/macro/Descriptor_type.hpp>
#include <objects/macro/Edit_action.hpp>
#include <objects/macro/Edit_featur_locatio_action.hpp>
#include <objects/macro/Edit_location_strand.hpp>
#include <objects/macro/ExistingTextOption.hpp>
#include <objects/macro/Extend_to_feature.hpp>
#include <objects/macro/Feat_qual_choice.hpp>
#include <objects/macro/Feat_qual_legal.hpp>
#include <objects/macro/Feat_qual_legal_set.hpp>
#include <objects/macro/Feat_qual_legal_val.hpp>
#include <objects/macro/Feat_qual_legal_val_choice.hpp>
#include <objects/macro/Featur_locatio_strand_from.hpp>
#include <objects/macro/Feature_field.hpp>
#include <objects/macro/Feature_field_legal.hpp>
#include <objects/macro/Feature_field_pair.hpp>
#include <objects/macro/Feature_location_strand_to.hpp>
#include <objects/macro/Feature_stranded_constrain.hpp>
#include <objects/macro/Field_constraint.hpp>
#include <objects/macro/Field_edit.hpp>
#include <objects/macro/Field_edit_location.hpp>
#include <objects/macro/Field_pair_type.hpp>
#include <objects/macro/Field_type.hpp>
#include <objects/macro/Fix_author_caps.hpp>
#include <objects/macro/Fix_caps_action.hpp>
#include <objects/macro/Fix_format_action.hpp>
#include <objects/macro/Fix_pub_caps_action.hpp>
#include <objects/macro/Fix_sets_action.hpp>
#include <objects/macro/Fix_type.hpp>
#include <objects/macro/Gene_xref_necessary_type.hpp>
#include <objects/macro/Gene_xref_suppression_type.hpp>
#include <objects/macro/Gene_xref_type.hpp>
#include <objects/macro/Location_choice.hpp>
#include <objects/macro/Location_constraint.hpp>
#include <objects/macro/Location_edit_type.hpp>
#include <objects/macro/Location_interval.hpp>
#include <objects/macro/Location_pos_constraint.hpp>
#include <objects/macro/Location_type_constraint.hpp>
#include <objects/macro/Macro_action_choice.hpp>
#include <objects/macro/Macro_action_list.hpp>
#include <objects/macro/Macro_feature_type.hpp>
#include <objects/macro/Make_gene_xref_action.hpp>
#include <objects/macro/Match_type_constraint.hpp>
#include <objects/macro/Misc_field.hpp>
#include <objects/macro/Molecule_class_type.hpp>
#include <objects/macro/Molecule_type.hpp>
#include <objects/macro/Molinfo_block.hpp>
#include <objects/macro/Molinfo_completedness_pair.hpp>
#include <objects/macro/Molinfo_field.hpp>
#include <objects/macro/Molinfo_field_constraint.hpp>
#include <objects/macro/Molinfo_field_list.hpp>
#include <objects/macro/Molinfo_field_pair.hpp>
#include <objects/macro/Molinfo_mol_class_pair.hpp>
#include <objects/macro/Molinfo_molecule_pair.hpp>
#include <objects/macro/Molinfo_strand_pair.hpp>
#include <objects/macro/Molinfo_technique_pair.hpp>
#include <objects/macro/Molinfo_topology_pair.hpp>
#include <objects/macro/Object_type_constraint.hpp>
#include <objects/macro/Parse_action.hpp>
#include <objects/macro/Parse_dest.hpp>
#include <objects/macro/Parse_dst_org.hpp>
#include <objects/macro/Parse_src.hpp>
#include <objects/macro/Parse_src_general_id.hpp>
#include <objects/macro/Parse_src_org.hpp>
#include <objects/macro/Parse_src_org_choice.hpp>
#include <objects/macro/Partial_3_clear_constraint.hpp>
#include <objects/macro/Partial_3_set_action.hpp>
#include <objects/macro/Partial_3_set_constraint.hpp>
#include <objects/macro/Partial_5_clear_constraint.hpp>
#include <objects/macro/Partial_5_set_action.hpp>
#include <objects/macro/Partial_5_set_constraint.hpp>
#include <objects/macro/Partial_both_clear_constra.hpp>
#include <objects/macro/Partial_both_set_action.hpp>
#include <objects/macro/Partial_both_set_constrain.hpp>
#include <objects/macro/Partial_constraint.hpp>
#include <objects/macro/Pub_field_constraint.hpp>
#include <objects/macro/Pub_field_speci_const_type.hpp>
#include <objects/macro/Pub_field_special_constrai.hpp>
#include <objects/macro/Pub_type.hpp>
#include <objects/macro/Publication_constraint.hpp>
#include <objects/macro/Publication_field.hpp>
#include <objects/macro/Quantity_constraint.hpp>
#include <objects/macro/Region_type.hpp>
#include <objects/macro/Remov_duplic_featur_action.hpp>
#include <objects/macro/Remove_action.hpp>
#include <objects/macro/Remove_descriptor_action.hpp>
#include <objects/macro/Remove_feature_action.hpp>
#include <objects/macro/Remove_outside_action.hpp>
#include <objects/macro/Remove_sequences_action.hpp>
#include <objects/macro/Remove_xrefs_action.hpp>
#include <objects/macro/Replace_func.hpp>
#include <objects/macro/Replace_rule.hpp>
#include <objects/macro/Retranslate_cds_action.hpp>
#include <objects/macro/Rna_feat_type.hpp>
#include <objects/macro/Rna_field.hpp>
#include <objects/macro/Rna_qual.hpp>
#include <objects/macro/Rna_qual_pair.hpp>
#include <objects/macro/Search_func.hpp>
#include <objects/macro/Seqtype_constraint.hpp>
#include <objects/macro/Seque_const_mol_type_const.hpp>
#include <objects/macro/Sequence_constraint.hpp>
#include <objects/macro/Sequence_constraint_rnamol.hpp>
#include <objects/macro/Sequence_list.hpp>
#include <objects/macro/Sequence_list_choice.hpp>
#include <objects/macro/Simple_replace.hpp>
#include <objects/macro/Site_type.hpp>
#include <objects/macro/Sort_fields_action.hpp>
#include <objects/macro/Sort_order.hpp>
#include <objects/macro/Source_constraint.hpp>
#include <objects/macro/Source_location.hpp>
#include <objects/macro/Source_origin.hpp>
#include <objects/macro/Source_qual.hpp>
#include <objects/macro/Source_qual_choice.hpp>
#include <objects/macro/Source_qual_pair.hpp>
#include <objects/macro/Source_qual_text_val.hpp>
#include <objects/macro/Source_qual_val_choice.hpp>
#include <objects/macro/Source_qual_val_set.hpp>
#include <objects/macro/Strand_constraint.hpp>
#include <objects/macro/Strand_type.hpp>
#include <objects/macro/String_constraint.hpp>
#include <objects/macro/String_constraint_set.hpp>
#include <objects/macro/String_location.hpp>
#include <objects/macro/Structu_comment_field_pair.hpp>
#include <objects/macro/Structured_comment_field.hpp>
#include <objects/macro/Suspect_rule.hpp>
#include <objects/macro/Suspect_rule_set.hpp>
#include <objects/macro/Swap_action.hpp>
#include <objects/macro/Table_match.hpp>
#include <objects/macro/Table_match_type.hpp>
#include <objects/macro/Technique_type.hpp>
#include <objects/macro/Text_marker.hpp>
#include <objects/macro/Text_portion.hpp>
#include <objects/macro/Text_transform.hpp>
#include <objects/macro/Text_transform_set.hpp>
#include <objects/macro/Topology_type.hpp>
#include <objects/macro/Translation_constraint.hpp>
#include <objects/macro/Truncate_ends_partial_type.hpp>
#include <objects/macro/Updat_repla_ec_numbe_actio.hpp>
#include <objects/macro/Update_sequences_action.hpp>
#include <objects/macro/Word_substitution.hpp>
#include <objects/macro/Word_substitution_set.hpp>
#include <objects/macro/Xref_type.hpp>
#include <objects/macro/NCBI_Macro_module.hpp>
