set(MODULES
    "dbg"
    "socket"
    "thread"
    "logger"
    "time"
    "type_cast"
    "mutex"
    "semaphore"
    "file"
    )
  
include(${CMAKE_MODULE_PATH}/gtest.cmake)
include(${CMAKE_MODULE_PATH}/core.cmake)
