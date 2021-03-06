CMAKE_MINIMUM_REQUIRED(VERSION 2.12)
PROJECT(immersive-media)

IF(NOT CMAKE_BUILD_TYPE)
  SET(CMAKE_BUILD_TYPE Release)
ENDIF()
MESSAGE("Build type: " ${CMAKE_BUILD_TYPE})

IF(NOT TARGET)
  MESSAGE(SEND_ERROR "\Set TARGET: server , client")
ENDIF()

IF(${TARGET} STREQUAL "server")
  SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -z noexecstack -z relro -z now -fstack-protector-strong -fPIE -fPIC -pie -O2 -D_FORTIFY_SOURCE=2 -Wformat -Wformat-security -Wl,-S  -Wall -std=c++11 -D_GLIBCXX_USE_CXX11_ABI=0 -lpthread -g")
  SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -z noexecstack -z relro -z now -fstack-protector-strong -fPIE -fPIC -pie -O2 -D_FORTIFY_SOURCE=2 -Wformat -Wformat-security -Wl,-S  -Wall -std=c++11 -D_GLIBCXX_USE_CXX11_ABI=0 -lpthread")
  SET(FFMPEG_DIR "ffmpeg")
  SET(FFMPEG_FILE "ffmpeg.txt")
  SET(FFMPEG_FLAG --prefix=/usr --libdir=/usr/lib --enable-static --disable-shared --enable-gpl --enable-nonfree --disable-optimizations --disable-vaapi --enable-libDistributedEncoder --enable-libVROmafPacking)
  include_directories(${CMAKE_CURRENT_SOURCE_DIR}/360SCVP)
  include_directories(${CMAKE_CURRENT_SOURCE_DIR}/VROmafPacking)
  ADD_SUBDIRECTORY(360SCVP)
  ADD_SUBDIRECTORY(VROmafPacking)
  ADD_CUSTOM_COMMAND(
      OUTPUT ${FFMPEG_FILE}
      COMMAND export PKG_CONFIG_PATH=${CMAKE_CURRENT_SOURCE_DIR}/VROmafPacking/:/usr/local/lib/pkgconfig/:$PKG_CONFIG_PATH && mkdir -p ${FFMPEG_DIR} && cd ${FFMPEG_DIR} && ${CMAKE_CURRENT_SOURCE_DIR}/FFmpeg/configure ${FFMPEG_FLAG} --extra-cflags="-I${CMAKE_CURRENT_SOURCE_DIR}/VROmafPacking/" --extra-cflags="-I${CMAKE_CURRENT_SOURCE_DIR}/360SCVP/" --extra-ldflags="-L${CMAKE_BINARY_DIR}/VROmafPacking/" --extra-ldflags="-L${CMAKE_BINARY_DIR}/360SCVP" && make -j100
      COMMENT "Building ffmpeg..."
      VERBATIM
  )
  ADD_CUSTOM_TARGET(ffmpeg ALL
      COMMAND echo "Target ffmpeg"
      DEPENDS ${FFMPEG_FILE}
      VERBATIM
  )

ELSEIF(${TARGET} STREQUAL "client")
  SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -z noexecstack -z relro -z now -fstack-protector-strong -fPIE -fPIC -pie -O2 -D_FORTIFY_SOURCE=2 -Wformat -Wformat-security -Wl,-S -Wall -std=c++11 -D_GLIBCXX_USE_CXX11_ABI=0 -I${CMAKE_CURRENT_SOURCE_DIR}/360SCVP -g")
  SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -z noexecstack -z relro -z now -fstack-protector-strong -fPIE -fPIC -pie -O2 -D_FORTIFY_SOURCE=2 -Wformat -Wformat-security -Wl,-S -Wall -std=c++11 -D_GLIBCXX_USE_CXX11_ABI=0 -I${CMAKE_CURRENT_SOURCE_DIR}/360SCVP")
  SET(UTILS_DIR "utils")
  SET(PLAYER_DIR "player")
  SET(PLAYER_FILE "player.txt")
  ADD_SUBDIRECTORY(360SCVP)
  ADD_SUBDIRECTORY(OmafDashAccess)
  ADD_CUSTOM_COMMAND(
      OUTPUT ${PLAYER_FILE}
      COMMAND cp ${CMAKE_CURRENT_SOURCE_DIR}/${UTILS_DIR}/data_type.h ${CMAKE_CURRENT_SOURCE_DIR}/${PLAYER_DIR} 
      COMMAND cp ${CMAKE_CURRENT_SOURCE_DIR}/${UTILS_DIR}/ns_def.h ${CMAKE_CURRENT_SOURCE_DIR}/${PLAYER_DIR} 
      COMMAND cp ${CMAKE_CURRENT_SOURCE_DIR}/${UTILS_DIR}/error.h ${CMAKE_CURRENT_SOURCE_DIR}/${PLAYER_DIR} 
      COMMAND cp ${CMAKE_CURRENT_SOURCE_DIR}/${UTILS_DIR}/OmafStructure.h ${CMAKE_CURRENT_SOURCE_DIR}/${PLAYER_DIR} 
      COMMAND cp ${CMAKE_CURRENT_SOURCE_DIR}/360SCVP/360SCVPAPI.h ${CMAKE_CURRENT_SOURCE_DIR}/${PLAYER_DIR} 
      COMMAND cp ${CMAKE_CURRENT_SOURCE_DIR}/OmafDashAccess/OmafDashAccessApi.h ${CMAKE_CURRENT_SOURCE_DIR}/${PLAYER_DIR} 
      COMMAND mkdir -p ${PLAYER_DIR} && cd ${PLAYER_DIR} && cmake -DUSE_OMAF=ON -DUSE_WEBRTC=OFF "-DCMAKE_CXX_FLAGS=-L${CMAKE_BINARY_DIR}/OmafDashAccess -L${CMAKE_BINARY_DIR}/360SCVP" ${CMAKE_CURRENT_SOURCE_DIR}/${PLAYER_DIR} && make
      COMMENT "Building player..."
      VERBATIM
  )
  ADD_CUSTOM_TARGET(player ALL
      COMMAND echo "Target player"
      DEPENDS ${PLAYER_FILE}
      VERBATIM
  )

ELSE()

  MESSAGE(SEND_ERROR "\Set TARGET_BUILD_TYPE : server , client")

ENDIF()
