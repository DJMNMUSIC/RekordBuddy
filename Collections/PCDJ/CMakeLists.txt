#
#  Rekord Buddy - The future proof music collection tool made by DJs for DJs.
#  Copyright (C) 2020-2021 Didier Malenfant (didier@rekordbuddy.org)
#
#  This program is free software: you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation, either version 3 of the License, or
#  (at your option) any later version.
#
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#
#  You should have received a copy of the GNU General Public License
#  along with this program.  If not, see <https://www.gnu.org/licenses/>.
#

cmake_minimum_required(VERSION 3.13)

nxa_project(PCDJCollection)

add_library(PCDJCollection STATIC
            Source/Crates/AllTracksPlaylist.cpp
            Source/Crates/Folder.cpp
            Source/Crates/Playlist.cpp
            Source/Tracks/Track.cpp
            Source/Collection.cpp
            Source/PCDJ.cpp)

target_include_directories(PCDJCollection
                           PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Include
                           PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Source)
target_link_libraries(PCDJCollection PUBLIC RekordBuddyCollection CommonCollection Base)

# -- These tests are from rekordbox right now so we disable them
#if(NXA_CMAKE_BUILD_FOR_TESTING)
#    add_subdirectory(Test)
#endif()

nxa_project_end()
