/*****************************************************************************
 * decoder.h: Input decoder functions
 *****************************************************************************
 * Copyright (C) 1998-2008 VLC authors and VideoLAN
 * Copyright (C) 2008 Laurent Aimar
 * $Id$
 *
 * Authors: Laurent Aimar <fenrir@via.ecp.fr>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/

#ifndef LIBVLC_INPUT_DECODER_H
#define LIBVLC_INPUT_DECODER_H 1

#include <vlc_common.h>
#include <vlc_codec.h>

decoder_t *input_DecoderNew( input_thread_t *, es_format_t *, input_clock_t *,
                             sout_instance_t * ) VLC_USED;

/**
 * This function changes the pause state.
 * The date parameter MUST hold the exact date at which the change has been
 * done for proper vout/aout pausing.
 */
void input_DecoderChangePause( decoder_t *, bool b_paused, vlc_tick_t i_date );

/**
 * This function changes the delay.
 */
void input_DecoderChangeDelay( decoder_t *, vlc_tick_t i_delay );

/**
 * This function makes the decoder start waiting for a valid data block from its fifo.
 */
void input_DecoderStartWait( decoder_t * );

/**
 * This function waits for the decoder to actually receive data.
 */
void input_DecoderWait( decoder_t * );

/**
 * This function exits the waiting mode of the decoder.
 */
void input_DecoderStopWait( decoder_t * );

/**
 * This function returns true if the decoder fifo is empty and false otherwise.
 */
bool input_DecoderIsEmpty( decoder_t * );

/**
 * This function activates the request closed caption channel.
 */
int input_DecoderSetCcState( decoder_t *, vlc_fourcc_t, int i_channel, bool b_decode );

/**
 * This function returns an error if the requested channel does not exist and
 * set pb_decode to the channel status(active or not) otherwise.
 */
int input_DecoderGetCcState( decoder_t *, vlc_fourcc_t, int i_channel, bool *pb_decode );

/**
 * This function get cc channels descriptions
 */
void input_DecoderGetCcDesc( decoder_t *, decoder_cc_desc_t * );

/**
 * This function force the display of the next picture and fills the stream
 * time consumed.
 */
void input_DecoderFrameNext( decoder_t *p_dec, vlc_tick_t *pi_duration );

/* Ask the decoder for one more frame without displaying anything. Used by
 * frame stepping, which shows the frame itself once it reaches the history. */
void input_DecoderRequestFrame( decoder_t *p_dec );

/**
 * Displays the buffered frame immediately before the one currently on
 * screen - no seek, no re-decode. The reference point is what the vout is
 * actually displaying, not the newest buffered frame, since the decoder
 * runs ahead of the display by a margin that varies with decode cost.
 * *pi_stream_date receives the displayed frame's stream timestamp, which
 * is the one a seek understands.
 * Returns VLC_EGENERIC if the buffer is disabled or empty, or if nothing
 * older than the current frame is held.
 */
int input_DecoderHistoryStepBack( decoder_t *p_dec, vlc_tick_t *pi_stream_date );

/**
 * Displays the buffered frame immediately after the one on screen.
 * Returns VLC_EGENERIC (harmlessly) when nothing newer is buffered - the
 * caller should fall back to a real forward decode step in that case.
 */
int input_DecoderHistoryStepForward( decoder_t *p_dec, vlc_tick_t *pi_stream_date );

/**
 * Returns true if the video track is currently displaying a frame from
 * its reverse-frame history buffer rather than the live decoded frame.
 */
bool input_DecoderHistoryIsActive( decoder_t *p_dec );

/**
 * Clears the reverse-frame history buffer, e.g. after a seek or other
 * discontinuity, so it never spans a jump in the timeline.
 */
void input_DecoderHistoryReset( decoder_t *p_dec );

/**
 * This function will return true if the ES format or meta data have changed since
 * the last call. In which case, it will do a copy of the current es_format_t if p_fmt
 * is not NULL and will do a copy of the current description if pp_meta is non NULL.
 * The es_format_t MUST be freed by es_format_Clean and *pp_meta MUST be freed by
 * vlc_meta_Delete.
 * Otherwise it will return false and will not initialize p_fmt and *pp_meta.
 */
bool input_DecoderHasFormatChanged( decoder_t *p_dec, es_format_t *p_fmt, vlc_meta_t **pp_meta );

/**
 * This function returns the current size in bytes of the decoder fifo
 */
size_t input_DecoderGetFifoSize( decoder_t *p_dec );

/**
 * This function returns the objects associated to a decoder
 *
 * They must be released using vlc_object_release().
 */
void input_DecoderGetObjects( decoder_t *, vout_thread_t **, audio_output_t ** );

#endif
