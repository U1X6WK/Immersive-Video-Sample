/*
 * Copyright (c) 2018, Intel Corporation
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

/* 
 * File:   error.h
 * Author: media
 *
 * Created on December 28, 2018, 10:15 AM
 */

#ifndef ERROR_H
#define ERROR_H

#define ERROR_NONE                               0
#define ERROR_INVALID                            -1
#define ERROR_PARSE                              -2
#define ERROR_THREAD                             -3
#define ERROR_MEMORY                             -4
#define ERROR_NULL_DOWNLOAD_MANAGER              -5
#define ERROR_SEG_NOT_READY                      -6
#define ERROR_DOWNLOAD_FAIL                      -7
#define ERROR_BAD_PARAM                          -8
#define ERROR_EOS                                -9
#define ERROR_NON_COMPLIANT_BITSTREAM            -10
#define ERROR_NULL_PACKET                        -11
#define ERROR_NO_STREAM                          -12
#define ERROR_NULL_PTR                           -13
#define ERROR_NOT_FOUND                          -14
#define ERROR_NO_VALUE                           -15
#define OMAF_ERROR_NULL_PTR                      -16
#define OMAF_ERROR_BAD_PARAM                     -17
#define OMAF_ERROR_UNDEFINED_OPERATION           -18
#define OMAF_ERROR_DATA_SIZE                     -19
#define OMAF_ERROR_VIDEO_NUM                     -20
#define OMAF_ERROR_ADD_MEDIASTREAMS              -21
#define OMAF_ERROR_CREATE_EXTRACTORTRACK_MANAGER -22
#define OMAF_ERROR_CREATE_SEGMENTATION           -23
#define OMAF_ERROR_MEDIA_TYPE                    -24
#define OMAF_ERROR_ADD_FRAMEINFO                 -25
#define OMAF_ERROR_CREATE_THREAD                 -26
#define OMAF_ERROR_VIDEO_RESOLUTION              -27
#define OMAF_ERROR_VIEWPORT_NUM                  -28
#define OMAF_ERROR_GET_RWPK                      -29
#define OMAF_ERROR_GET_COVI                      -30
#define OMAF_ERROR_NALU_NOT_FOUND                -31
#define OMAF_ERROR_INVALID_SPS                   -32
#define OMAF_ERROR_INVALID_PPS                   -33
#define OMAF_ERROR_INVALID_RWPK                  -34
#define OMAF_ERROR_INVALID_COVI                  -35
#define OMAF_ERROR_SCVP_INIT_FAILED              -36
#define OMAF_ERROR_INVALID_HEADER                -37
#define OMAF_ERROR_INVALID_FRAME_BITSTREAM       -38
#define OMAF_ERROR_SCVP_SET_FAILED               -39
#define OMAF_ERROR_SCVP_PROCESS_FAILED           -40
#define OMAF_ERROR_SCVP_INCORRECT_RESULT         -41
#define OMAF_ERROR_SCVP_OPERATION_FAILED         -42
#define OMAF_ERROR_INVALID_DATA                  -43
#define OMAF_ERROR_INVALID_PROJECTIONTYPE        -44
#define OMAF_ERROR_CHANGE_FOLDERMODE_FAILED      -45
#define OMAF_ERROR_CREATE_FOLDER_FAILED          -46
#define OMAF_ERROR_CREATE_XMLFILE_FAILED         -47
#define OMAF_ERROR_INVALID_TRACKSEG_CTX          -48
#define OMAF_ERROR_END_OF_STREAM                 -80
#define OMAF_MEMORY_TOO_SMALL_BUFFER             -81
#define OMAF_ERROR_STREAM_NOT_FOUND              -82
#define OMAF_ERROR_INVALID_REF_TRACK             -83
#define OMAF_ERROR_INVALID_TIME                  -84
#define OMAF_ERROR_EXTRACTOR_NOT_FOUND           -85
#define OMAF_ERROR_EXTRACTORTRACK_NOT_FOUND      -86

#endif /* ERROR_H */

