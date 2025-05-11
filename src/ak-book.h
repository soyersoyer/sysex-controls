#pragma once

#include <adwaita.h>
#include "sc-book.h"

#define AKAI_MPK1_ID 0x7c
#define AKAI_MPK2_ID 0x26
#define AKAI_MPK3_ID 0x49

// From: https://github.com/gljubojevic/akai-mpk-mini-editor
// https://github.com/rubimat/akai_mpk_mini_flasher
// https://github.com/carlosedp/Reason-MPKMini-Remote/blob/master/Remote/Codecs/Lua%20Codecs/Akai/AkaiMPKmini.lua
#define AKAI_CMD_V1_SEND 0x61
#define AKAI_CMD_V1_QUERY 0x63
#define AKAI_CMD_V1_RECEIVE 0x63

#define AKAI_CMD_SELECT 0x62
#define AKAI_CMD_SEND 0x64
#define AKAI_CMD_QUERY 0x66
#define AKAI_CMD_RECEIVE 0x67

G_BEGIN_DECLS

#define AK_TYPE_BOOK (ak_book_get_type ())

G_DECLARE_DERIVABLE_TYPE (AkBook, ak_book, AK, BOOK, ScBook)

struct _AkBookClass
{
  ScBookClass parent_class;

  int (*read_program) (snd_seq_t *seq, snd_seq_addr_t addr, uint8_t dev_id, uint8_t query_cmd, uint8_t recv_cmd, uint8_t prog_id, uint8_t *data, uint16_t *size);
  int (*write_program) (snd_seq_t *seq, snd_seq_addr_t addr, uint8_t dev_id, uint8_t send_cmd, uint8_t prog_id, uint8_t *data, uint16_t size);
  int (*select_program) (snd_seq_t *seq, snd_seq_addr_t addr, uint8_t dev_id, uint8_t sel_cmd, uint8_t prog_id);
};

void ak_book_set_dev_id (AkBook *self, uint8_t dev_id);
void ak_book_set_query_cmd (AkBook *self, uint8_t query_cmd);
void ak_book_set_recv_cmd (AkBook *self, uint8_t recv_cmd);
void ak_book_set_send_cmd (AkBook *self, uint8_t send_cmd);
void ak_book_set_sel_cmd (AkBook *self, uint8_t sel_cmd);

int ak_book_read_program (AkBook *self, uint8_t prog_id, uint8_t *dat, uint16_t *size);
int ak_book_write_program (AkBook *self, uint8_t prog_id, uint8_t *data, uint16_t size);

int ak_book_select_program (AkBook *self, uint8_t prog_id);

void ak_book_refresh_page (AkBook *self, uint8_t prog_id);

void ak_book_use_dummy (ScBook *self);

G_END_DECLS
