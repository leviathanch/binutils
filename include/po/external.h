/* IBM z/OS Program Object support
   Copyright (C) 2018 Rocket Software
   Contributed by Michael Colavita (mcolavita@rocketsoftware.com)
 
   This file is part of BFD, the Binary File Descriptor library.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA
   02110-1301, USA.  */

#ifndef _PO_EXTERNAL_H
#define _PO_EXTERNAL_H

/*
 * IEWPLMH: header
 */

struct po_external_plmh {
  unsigned char fixed_eyecatcher[8];
  unsigned char length[4];
  unsigned char version;
  unsigned char reserved0[3]; /* MBZ */
  unsigned char uncompressed_module_size[4];
  unsigned char rec_decl_count[4];
};


/*
 * IEWPLMH repeating section
 */

struct po_external_header_rec_decl {
  unsigned char rec_type[2];
  unsigned char reserved0[2]; /* MBZ */
  unsigned char rec_offset[4];
  unsigned char rec_length[4];
};

/* TODO: demonic */

/*
 * IEWPMAR
 */

struct po_external_pmar {
  unsigned char length[2];
  unsigned char po_level;
  unsigned char binder_level;
  unsigned char attr1;
  unsigned char attr2;
  unsigned char attr3;
  unsigned char attr4;
  unsigned char attr5;
  unsigned char apf_auth_code;
  unsigned char virtual_storage_required[4];
  unsigned char main_entry_point_offset[4];
  unsigned char this_entry_point_offset[4];
  unsigned char change_level_of_member;
  unsigned char ssi_flag_byte;
  unsigned char member_serial_number[2];
  unsigned char extended_attributes[2];
  unsigned char reserved0[2]; /* MBZ */
};


/*
 * IEWPMARL
 */

struct po_external_pmarl {
  unsigned char length[2];
  unsigned char attr1;
  unsigned char attr2;
  unsigned char fill_char_value;
  unsigned char po_sublevel;
  unsigned char program_length_no_gas[4];
  unsigned char program_length_gas[4];
  unsigned char offset_text[4];
  unsigned char offset_binder_index[4];
  unsigned char prdt_length[4];
  unsigned char prdt_offset[4];
  unsigned char prat_length[4];
  unsigned char prat_offset[4];
  unsigned char po_virtual_pages[4];
  unsigned char ls_loader_data_length[4];
  /* TODO: PM2 deliniation? */
  unsigned char loadable_segment_count[2];
  unsigned char gas_table_entry_count[2];
  unsigned char virtual_storage_for_first_segment[4];
  unsigned char virtual_storage_for_second_segment[4];
  unsigned char offset_to_second_text_segment[4];
  unsigned char date_saved[4]; /* Julian packed decimal */
  unsigned char time_saved[4]; /* packed decimal hhmmss */
  unsigned char userid[8];
  /* TODO: PM3 deliniation? */
  unsigned char pm3_flags;
  unsigned char cms_flags;
  unsigned char deferred_class_count[2];
  unsigned char deferred_class_total_length[4];
  unsigned char offset_to_first_deferred_class[4];
  unsigned char offset_blit[4];
  /* TODO: PM4 deliniation? */
  unsigned char attr3;
  unsigned char reserved0[7]; /* MBZ */
  /* TODO: PM5 deliniation? */
};

/*
 * IEWPRAT
 */
struct po_external_prat {
  unsigned char fixed_eyecatcher[8];
  unsigned char length[4];
  unsigned char version;
  unsigned char reserved0[3]; /* MBZ */
  unsigned char unknown0[4]; /* TODO */
  unsigned char unknown1[4]; /* TODO */
  unsigned char unknown2[4]; /* TODO */
  /* range pairs? TODO */
};

/*
 * IEWPRAT range pair
 */
struct po_external_prat_range {
  unsigned char begin[2];
  unsigned char end[2];
};

/*
 * IEWPRDT
 */
struct po_external_prdt {
  unsigned char fixed_eyecather[8];
  unsigned char length[4];
  unsigned char version;
  unsigned char reserved0[3]; /* MBZ */
  unsigned char total_length[4];
};

/*
 * IEWPRDT page reloc repeating section
 */
struct po_external_prdt_page_relocs {
  unsigned char page_number[4];
  unsigned char segment_index[2];
  unsigned char checksum[4];
  unsigned char reloc_count_total[2];
  unsigned char flags;
  unsigned char reference_id; /* TODO? */
  unsigned char reloc_count_six_byte[2];
};

struct po_external_prdt_six_byte_reloc {
  unsigned char offset[2];
  unsigned char value[4];
};

struct po_external_prdt_eight_byte_reloc {
  unsigned char unknown[2];
  unsigned char offset[2];
  unsigned char value[4];
};

/*
 * IEWLIDX: list header
 */
struct po_external_lidx {
  unsigned char fixed_eyecatcher[8];
  unsigned char length[4];
  unsigned char version;
  unsigned char reserved0[3]; /* MBZ */
  unsigned char element_count[4];
};

/*
 * IEWLIDX entry
 */

struct po_external_lidx_entry {
  unsigned char type;
  unsigned char reserved0[3]; /* MBZ */
  unsigned char entry_offset[4];
  unsigned char entry_length[4];
};

/*
 * IEWPSEGM
 */
struct po_external_psegm {
  unsigned char fixed_eyecatcher[8];
  unsigned char length[4];
  unsigned char version;
  unsigned char reserved0[3]; /* MBZ */
  unsigned char entry_count[4];
};

/*
 * IEWPSEGM entry
 */


struct po_external_psegm_entry {
  unsigned char length[4];
  unsigned char offset[4];
  unsigned char reserved0[4]; /* MBZ */
  unsigned char flags;
  unsigned char reserved1[3]; /* MBZ */
};

/*
 * IEWPGSTB: decompression/expansion table
 */
struct po_external_pgstb {
  unsigned char fixed_eyecatcher[8];
  unsigned char length[4];
  unsigned char version;
  unsigned char reserved0[3]; /* MBZ */
  unsigned char entry_count[4];
};

/*
 * IEWPGSTB expansion entry
 */
struct po_external_pgstb_entry {
  unsigned char start_inclusive[4];
  unsigned char end_inclusive[4];
};

/* TODO:
 *  - LCIB
 *  - LDSIL
 *  - BLIT
 *  - LFMD
 *  - BXLF
 *  - PMAP
 */

#define PLMH_BASE_SIZE                 (sizeof(struct po_external_plmh))
#define PLMH_SIZE(x)                   (PLMH_BASE_SIZE + (x) * HEADER_REC_DECL_SIZE)
#define PLMH_MAX_SIZE                  (PLMH_SIZE(8))

#define HEADER_REC_DECL_SIZE           (sizeof(struct po_external_header_rec_decl))

#define PMAR_SIZE                      (sizeof(struct po_external_pmar))

#endif

