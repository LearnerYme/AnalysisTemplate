cmake_minimum_required(VERSION 3.26)
project(AnalysisTemplate CXX)

set(
        AnalysisTree_Home
        /Users/huangyige/Work/DataAnalysis/gsi/AnalysisTree
        )

set(
        AnalysisTree_Sys
        ${AnalysisTree_Home}/build/AnalysisTree
        )
     
list(
        APPEND 
        CMAKE_PREFIX_PATH 
        $ENV{ROOTSYS}
        )

list(
        APPEND 
        CMAKE_PREFIX_PATH 
        ${AnalysisTree_Sys}
        )

find_package(ROOT 6.24 CONFIG REQUIRED)
find_package(Boost REQUIRED)
find_package(AnalysisTree REQUIRED)
message(STATUS "CMAKE_PROJECT_NAME ${CMAKE_PROJECT_NAME}")

include_directories(
        ${AnalysisTree_Home}/core 
        ${AnalysisTree_Home}/infra 
        ${CMAKE_CURRENT_SOURCE_DIR} 
        ${Boost_INCLUDE_DIRS}
        )

set(
        ADD_TOOLS
        MultiplicityTool/MultiplicityTool.cxx
        IdxConstants/IdxConstants.cxx
        DuplicateRemover/DuplicateRemover.cxx
)

add_library(AnalysisTreeUser SHARED ${ADD_TOOLS} G__AnalysisTreeUser.cxx)
target_compile_definitions(
        AnalysisTreeUser 
        PUBLIC
        ${ANALYSISTREE_BOOST_FOUND}
        )

ROOT_GENERATE_DICTIONARY(
        G__AnalysisTreeUser 
        ${HEADERS}
        LINKDEF AnalysisTreeUserLinkDef.h
        OPTIONS
        -I${CMAKE_BINARY_DIR}/include
        $<$<BOOL:${Boost_FOUND}>:-DANALYSISTREE_BOOST_FOUND>
        )

target_link_libraries(
        AnalysisTreeUser
        PUBLIC
        ${ROOT_LIBRARIES}
        AnalysisTreeBase 
        AnalysisTreeInfra
        $<$<BOOL:${Boost_FOUND}>:${Boost_LIBRARIES}>
        )

include(${ROOT_USE_FILE})
include_directories(${ROOT_INCLUDE_DIR} ${ROOT_INCLUDE_DIRS} ${AnalysisTree_INCLUDE_DIR})

add_executable(AnalysisTemplate AnalysisTemplate.cpp)
target_link_libraries(AnalysisTemplate ${ROOT_LIBRARIES} AnalysisTreeBase AnalysisTreeInfra AnalysisTreeUser)

