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

#include "sysdep.h"
#include "bfd.h"
#include "bfdlink.h"
#include "libbfd.h"
#include "po-bfd.h"

__attribute__((unused))
static
const unsigned char ibm1047_to_iso88591[256] = {
/*         0     1     2     3     4     5     6     7     8     9     A     B     C     D     E     F */
/* 0 */ 0x00, 0x01, 0x02, 0x03, 0x9C, 0x09, 0x86, 0x7F, 0x97, 0x8D, 0x8E, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
/* 1 */ 0x10, 0x11, 0x12, 0x13, 0x9D, 0x0A, 0x08, 0x87, 0x18, 0x19, 0x92, 0x8F, 0x1C, 0x1D, 0x1E, 0x1F,
/* 2 */ 0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x17, 0x1B, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x05, 0x06, 0x07,
/* 3 */ 0x90, 0x91, 0x16, 0x93, 0x94, 0x95, 0x96, 0x04, 0x98, 0x99, 0x9A, 0x9B, 0x14, 0x15, 0x9E, 0x1A,
/* 4 */ 0x20, 0xA0, 0xE2, 0xE4, 0xE0, 0xE1, 0xE3, 0xE5, 0xE7, 0xF1, 0xA2, 0x2E, 0x3C, 0x28, 0x2B, 0x7C,
/* 5 */ 0x26, 0xE9, 0xEA, 0xEB, 0xE8, 0xED, 0xEE, 0xEF, 0xEC, 0xDF, 0x21, 0x24, 0x2A, 0x29, 0x3B, 0x5E,
/* 6 */ 0x2D, 0x2F, 0xC2, 0xC4, 0xC0, 0xC1, 0xC3, 0xC5, 0xC7, 0xD1, 0xA6, 0x2C, 0x25, 0x5F, 0x3E, 0x3F,
/* 7 */ 0xF8, 0xC9, 0xCA, 0xCB, 0xC8, 0xCD, 0xCE, 0xCF, 0xCC, 0x60, 0x3A, 0x23, 0x40, 0x27, 0x3D, 0x22,
/* 8 */ 0xD8, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0xAB, 0xBB, 0xF0, 0xFD, 0xFE, 0xB1,
/* 9 */ 0xB0, 0x6A, 0x6B, 0x6C, 0x6D, 0x6E, 0x6F, 0x70, 0x71, 0x72, 0xAA, 0xBA, 0xE6, 0xB8, 0xC6, 0xA4,
/* A */ 0xB5, 0x7E, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, 0x79, 0x7A, 0xA1, 0xBF, 0xD0, 0x5B, 0xDE, 0xAE,
/* B */ 0xAC, 0xA3, 0xA5, 0xB7, 0xA9, 0xA7, 0xB6, 0xBC, 0xBD, 0xBE, 0xDD, 0xA8, 0xAF, 0x5D, 0xB4, 0xD7,
/* C */ 0x7B, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0xAD, 0xF4, 0xF6, 0xF2, 0xF3, 0xF5,
/* D */ 0x7D, 0x4A, 0x4B, 0x4C, 0x4D, 0x4E, 0x4F, 0x50, 0x51, 0x52, 0xB9, 0xFB, 0xFC, 0xF9, 0xFA, 0xFF,
/* E */ 0x5C, 0xF7, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x5A, 0xB2, 0xD4, 0xD6, 0xD2, 0xD3, 0xD5,
/* F */ 0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0xB3, 0xDB, 0xDC, 0xD9, 0xDA, 0x9F};

__attribute__((unused))
static
const unsigned char iso88591_to_ibm1047[256] = {
/*         0     1     2     3     4     5     6     7     8     9     A     B     C     D     E     F */
/* 0 */ 0x00, 0x01, 0x02, 0x03, 0x37, 0x2D, 0x2E, 0x2F, 0x16, 0x05, 0x15, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
/* 1 */ 0x10, 0x11, 0x12, 0x13, 0x3C, 0x3D, 0x32, 0x26, 0x18, 0x19, 0x3F, 0x27, 0x1C, 0x1D, 0x1E, 0x1F,
/* 2 */ 0x40, 0x5A, 0x7F, 0x7B, 0x5B, 0x6C, 0x50, 0x7D, 0x4D, 0x5D, 0x5C, 0x4E, 0x6B, 0x60, 0x4B, 0x61,
/* 3 */ 0xF0, 0xF1, 0xF2, 0xF3, 0xF4, 0xF5, 0xF6, 0xF7, 0xF8, 0xF9, 0x7A, 0x5E, 0x4C, 0x7E, 0x6E, 0x6F,
/* 4 */ 0x7C, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xD1, 0xD2, 0xD3, 0xD4, 0xD5, 0xD6,
/* 5 */ 0xD7, 0xD8, 0xD9, 0xE2, 0xE3, 0xE4, 0xE5, 0xE6, 0xE7, 0xE8, 0xE9, 0xAD, 0xE0, 0xBD, 0x5F, 0x6D,
/* 6 */ 0x79, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96,
/* 7 */ 0x97, 0x98, 0x99, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xC0, 0x4F, 0xD0, 0xA1, 0x07,
/* 8 */ 0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x06, 0x17, 0x28, 0x29, 0x2A, 0x2B, 0x2C, 0x09, 0x0A, 0x1B,
/* 9 */ 0x30, 0x31, 0x1A, 0x33, 0x34, 0x35, 0x36, 0x08, 0x38, 0x39, 0x3A, 0x3B, 0x04, 0x14, 0x3E, 0xFF,
/* A */ 0x41, 0xAA, 0x4A, 0xB1, 0x9F, 0xB2, 0x6A, 0xB5, 0xBB, 0xB4, 0x9A, 0x8A, 0xB0, 0xCA, 0xAF, 0xBC,
/* B */ 0x90, 0x8F, 0xEA, 0xFA, 0xBE, 0xA0, 0xB6, 0xB3, 0x9D, 0xDA, 0x9B, 0x8B, 0xB7, 0xB8, 0xB9, 0xAB,
/* C */ 0x64, 0x65, 0x62, 0x66, 0x63, 0x67, 0x9E, 0x68, 0x74, 0x71, 0x72, 0x73, 0x78, 0x75, 0x76, 0x77,
/* D */ 0xAC, 0x69, 0xED, 0xEE, 0xEB, 0xEF, 0xEC, 0xBF, 0x80, 0xFD, 0xFE, 0xFB, 0xFC, 0xBA, 0xAE, 0x59,
/* E */ 0x44, 0x45, 0x42, 0x46, 0x43, 0x47, 0x9C, 0x48, 0x54, 0x51, 0x52, 0x53, 0x58, 0x55, 0x56, 0x57,
/* F */ 0x8C, 0x49, 0xCD, 0xCE, 0xCB, 0xCF, 0xCC, 0xE1, 0x70, 0xDD, 0xDE, 0xDB, 0xDC, 0x8D, 0x8E, 0xDF};

static const char eyecatcher_plmh[] = { 0xC9, 0xC5, 0xE6, 0xD7, 0xD3, 0xD4, 0xC8, 0x40 };

static void
convert_iso88591_to_ibm1047 (char *ascii, char *ebcdic, bfd_size_type length)
{
  for (unsigned i = 0; i < length; i ++)
    ebcdic[i] = iso88591_to_ibm1047[(int) ascii[i]];
}

static void
bfd_po_swap_plmh_out (bfd *abfd, struct po_internal_plmh *src, struct po_external_plmh *dst)
{
  memset(dst, 0, sizeof(*dst));
  memcpy(dst->fixed_eyecatcher, src->fixed_eyecatcher, sizeof(dst->fixed_eyecatcher));
  dst->version = src->version;
  H_PUT_32 (abfd, src->length, &dst->length);
  H_PUT_32 (abfd, src->uncompressed_module_size, &dst->uncompressed_module_size);
  H_PUT_32 (abfd, src->rec_decl_count, &dst->rec_decl_count);
}

static void
bfd_po_swap_header_rec_decl_out (bfd *abfd, struct po_internal_header_rec_decl *src, struct po_external_header_rec_decl *dst)
{
  memset(dst, 0, sizeof(*dst));
  H_PUT_16 (abfd, src->rec_type, &dst->rec_type);
  H_PUT_32 (abfd, src->rec_offset, &dst->rec_offset);
  H_PUT_32 (abfd, src->rec_length, &dst->rec_length);
}

static void
bfd_po_swap_pmar_out (bfd *abfd, struct po_internal_pmar *src, struct po_external_pmar *dst)
{
  H_PUT_16 (abfd, src->length, &dst->length);
  dst->po_level = src->po_level;
  dst->binder_level = src->binder_level;
  dst->attr1 = src->attr1;
  dst->attr2 = src->attr2;
  dst->attr3 = src->attr3;
  dst->attr4 = src->attr4;
  dst->attr5 = src->attr5;
  dst->apf_auth_code = src->apf_auth_code;
  H_PUT_32 (abfd, src->virtual_storage_required, &dst->virtual_storage_required);
  H_PUT_32 (abfd, src->main_entry_point_offset, &dst->main_entry_point_offset);
  H_PUT_32 (abfd, src->this_entry_point_offset, &dst->this_entry_point_offset);
  dst->change_level_of_member = src->change_level_of_member;
  dst->ssi_flag_byte = src->ssi_flag_byte;
  memcpy(dst->member_serial_number, src->member_serial_number, sizeof(dst->member_serial_number));
  memcpy(dst->extended_attributes, src->extended_attributes, sizeof(dst->extended_attributes));
}

static bfd_boolean
bfd_po_write_header (__attribute__((unused)) bfd *abfd)
{
  /* Finalize header */
  unsigned int rec_count = 2;
  po_header(abfd).length = PLMH_SIZE(rec_count);
  po_header(abfd).uncompressed_module_size = PLMH_SIZE(rec_count) + sizeof (struct po_external_pmar); /* TODO */
  po_header(abfd).rec_decl_count = rec_count;
  po_header(abfd).rec_decls = bfd_zmalloc2(rec_count, HEADER_REC_DECL_SIZE);

  po_header(abfd).rec_decls[0] = (struct po_internal_header_rec_decl) {
    .rec_type = PLMH_REC_TYPE_PO_NAME,
    .rec_offset = PLMH_SIZE(2),
    .rec_length = PO_NAME_SIZE
  };

  po_header(abfd).rec_decls[1] = (struct po_internal_header_rec_decl) {
    .rec_type = PLMH_REC_TYPE_PMAR,
    .rec_offset = PLMH_SIZE(2) + PO_NAME_SIZE,
    .rec_length = sizeof(struct po_external_pmar)
  };

  /* Finalize PMAR TODO */

  /* Finalize PMARL TODO */

  /* Output header */
  char header_buf[PLMH_MAX_SIZE];
  bfd_po_swap_plmh_out(abfd, &po_header(abfd), (struct po_external_plmh *) header_buf);
  for (unsigned int i = 0; i < rec_count; i ++)
    bfd_po_swap_header_rec_decl_out(abfd, &po_header(abfd).rec_decls[i], (struct po_external_header_rec_decl *) (header_buf + PLMH_SIZE(i)));

  if (bfd_seek(abfd, 0, SEEK_SET) != 0 || bfd_bwrite(header_buf, po_header(abfd).length, abfd) != po_header(abfd).length)
    goto fail_free;

  /* Output demonic thing TODO */

  /* Output PO name */
  char name_ibm1047[PO_NAME_SIZE];
  convert_iso88591_to_ibm1047(po_name(abfd), name_ibm1047, PO_NAME_SIZE);
  if (bfd_bwrite(name_ibm1047, PO_NAME_SIZE, abfd) != PO_NAME_SIZE)
    goto fail_free;

  /* Output PMAR */
  char pmar[PMAR_SIZE];
  bfd_po_swap_pmar_out(abfd, &po_pmar(abfd), (struct po_external_pmar *) pmar);
  if (bfd_bwrite(pmar, PMAR_SIZE, abfd) != PMAR_SIZE)
    goto fail_free;

  /* Output PMARL */

  return TRUE;

fail_free:
  free(po_header(abfd).rec_decls);
  return FALSE;
}

static bfd_boolean
bfd_po_new_section_hook (bfd *abfd, sec_ptr sec)
{
  return _bfd_generic_new_section_hook (abfd, sec);
}

static bfd_boolean
bfd_po_set_section_contents (__attribute ((unused)) bfd *abfd, __attribute ((unused)) sec_ptr sec, __attribute ((unused)) const void *contents, __attribute ((unused)) file_ptr offset, __attribute ((unused)) bfd_size_type len)
{
  // const struct bfd_po_section_data *sdata;
  // sdata = (struct bfd_po_section_data *) sec->used_by_bfd;

  // printf("size %lu\n", sec->size);
  // printf("name %s\n", sec->name);

  // return _bfd_generic_set_section_contents(abfd, sec, contents, offset, len);

  return TRUE;
}

static bfd_boolean
bfd_po_mkobject (bfd *abfd)
{
  abfd->tdata.any = bfd_zalloc (abfd, sizeof (struct po_obj_tdata));
  if (abfd->tdata.any == NULL)
    return FALSE;

  /* Initialize internal header */
  memcpy(po_header(abfd).fixed_eyecatcher, eyecatcher_plmh, sizeof(eyecatcher_plmh));
  po_header(abfd).version = PLMH_VERSION;

  /* Initialize PMAR */
  po_pmar(abfd).length = sizeof(struct po_external_pmar);
  po_pmar(abfd).po_level = PMAR_PO_LEVEL_PM3;
  po_pmar(abfd).binder_level = PMAR_BINDER_LEVEL_B5;

  /* Set default PMAR flags */
  po_pmar(abfd).attr1 |= PMAR_ATTR1_EXECUTABLE;
  po_pmar(abfd).attr2 |= PMAR_ATTR2_BINDER_F_LEVEL_REQ;
  po_pmar(abfd).attr2 |= PMAR_ATTR2_ORG0;
  po_pmar(abfd).attr2 |= PMAR_ATTR2_NO_RLD;
  po_pmar(abfd).attr2 |= PMAR_ATTR2_NO_REPROCESS;
  po_pmar(abfd).attr3 |= PMAR_ATTR3_PMARL_PRESENT;
  po_pmar(abfd).attr4 |= PMAR_ATTR4_RMODE31;
  po_pmar(abfd).attr4 |= PMAR_AMODE64;

  /* Initialize PMARL */
  po_pmarl(abfd).length = sizeof(struct po_external_pmarl);

  /* Set default PMARL flags */
  po_pmarl(abfd).attr1 |= PMARL_ATTR1_NO_PDS_CONVERT;
  po_pmarl(abfd).attr1 |= PMARL_ATTR2_SEG1_RMODE31;
  memset(po_pmarl(abfd).userid, ' ', sizeof(po_pmarl(abfd).userid));

  /* Clear PO name */
  memset(&po_name(abfd), ' ', sizeof(po_name(abfd)));

  return TRUE;
}

static bfd_boolean
bfd_po_write_object_contents (bfd *abfd)
{
  // asection *current;

  // for (current = abfd->sections; current != NULL; current = current->next)
  //   {
  //     const struct bfd_po_section_data *sdata;
  //     printf("Section (%lu bytes):\n", current->size);
  //     printf("  Name: %s\n", current->name);
  //     printf("  Contents:\n");
  //     if (current->flags & SEC_HAS_CONTENTS) {
  //       sdata = (struct bfd_po_section_data *) current->used_by_bfd;

  //       for (unsigned i = 0; i < sdata->contents_length; i += 16) {
  //         for (unsigned i2 = i; i2 < i + 16 && i2 < sdata->contents_length; i2 ++) {
  //           printf("%02x", sdata->contents_buffer[i2]);
  //         }
  //         printf("\n");
  //       }
  //     } else {
  //       printf("    No content.\n");
  //     }

  //     printf("\n");
  //   }
  bfd_po_write_header (abfd);

  return TRUE;
}

const bfd_target s390_po_vec = {
  "po-s390",
  bfd_target_unknown_flavour,
  BFD_ENDIAN_BIG,
  BFD_ENDIAN_BIG,

  (BFD_RELOC_8 | BFD_RELOC_16 | BFD_RELOC_24 | BFD_RELOC_32 | EXEC_P | HAS_SYMS | WP_TEXT),
  (SEC_ALLOC | SEC_LOAD | SEC_RELOC | SEC_HAS_CONTENTS),
  0,
  ' ',
  8,
  4,

  bfd_getb64, bfd_getb_signed_64, bfd_putb64,
    bfd_getb32, bfd_getb_signed_32, bfd_putb32,
    bfd_getb16, bfd_getb_signed_16, bfd_putb16,

  bfd_getb64, bfd_getb_signed_64, bfd_putb64,
    bfd_getb32, bfd_getb_signed_32, bfd_putb32,
    bfd_getb16, bfd_getb_signed_16, bfd_putb16,

  { 
    _bfd_dummy_target,
    _bfd_dummy_target, /* TODO: bfd_po_object_p */
    _bfd_dummy_target,
    _bfd_dummy_target
  },

  {
    _bfd_bool_bfd_false_error,
    bfd_po_mkobject,
    _bfd_bool_bfd_false_error,
    _bfd_bool_bfd_false_error
  },

  {
    _bfd_bool_bfd_false_error,
    bfd_po_write_object_contents,
    _bfd_bool_bfd_false_error,
    _bfd_bool_bfd_false_error
  },

  _bfd_generic_close_and_cleanup,
  _bfd_generic_bfd_free_cached_info,
  bfd_po_new_section_hook,
  _bfd_generic_get_section_contents,
  _bfd_generic_get_section_contents_in_window,
  BFD_JUMP_TABLE_COPY(_bfd_generic), /* TODO? */
  BFD_JUMP_TABLE_CORE(_bfd_nocore),
  BFD_JUMP_TABLE_ARCHIVE(_bfd_noarchive), /* TODO */
  BFD_JUMP_TABLE_SYMBOLS(_bfd_nosymbols), /* TODO */
  BFD_JUMP_TABLE_RELOCS(_bfd_norelocs), /* TODO */
  _bfd_generic_set_arch_mach,
  bfd_po_set_section_contents,
  BFD_JUMP_TABLE_LINK(_bfd_nolink), /* TODO */
  BFD_JUMP_TABLE_DYNAMIC(_bfd_nodynamic),

  NULL,

  NULL
};

