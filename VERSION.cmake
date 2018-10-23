# (C) Copyright 1996-2016 ECMWF.
#
# This software is licensed under the terms of the Apache Licence Version 2.0
# which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
# In applying this licence, ECMWF does not waive the privileges and immunities
# granted to it by virtue of its status as an intergovernmental organisation nor
# does it submit to any jurisdiction.


set ( metabuilder_version 3.3.0 )
set ( _version 3.3.0 )


if ( MAGICS_BUILD )
  set( ${PROJECT_NAME}_VERSION_STR  "${metabuilder_version}-${MAGICS_BUILD}" )
else ()
  set( ${PROJECT_NAME}_VERSION_STR  ${metabuilder_version})
endif()

set( BRANCH_NAME ${${PROJECT_NAME}_VERSION_STR} )
