/*
 * Copyright (c) 2015 Advanced Micro Devices, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met: redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer;
 * redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution;
 * neither the name of the copyright holders nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef __SIM_REDIRECT_PATH_HH__
#define __SIM_REDIRECT_PATH_HH__

#include <string>
#include <vector>

#include "params/RedirectPath.hh"
#include "sim/sim_object.hh"

namespace gem5
{

/**
 * RedirectPath stores a mapping from one 'appPath' to a vector of
 * 'hostPath'. Each 'appPath' and 'hostPath' is a filesystem path.
 * Used by process.cc to redirect syscall accesses to different directories.
 */
class RedirectPath : public SimObject
{
  public:
    RedirectPath(const RedirectPathParams &p);

    const std::string& appPath() { return _appPath; };
    const std::vector<std::string>& hostPaths() { return _hostPaths; };

  protected:
    /**
     * An appPath is a path which needs to be redirected and replaced
     * by one of the corresponding hostPath (when accessing files on the host
     * filesystem.)
     */
     // _appPath holds the path as it would appear from an app's perspective.
    std::string _appPath;
     // _hostPaths holds a set of host filesystem paths
    std::vector<std::string> _hostPaths;
};

} // namespace gem5

#endif
