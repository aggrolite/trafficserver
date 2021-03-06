/** @file

  Inlines base64 images from the ATS cache

  @section license License

  Licensed to the Apache Software Foundation (ASF) under one
  or more contributor license agreements.  See the NOTICE file
  distributed with this work for additional information
  regarding copyright ownership.  The ASF licenses this file
  to you under the Apache License, Version 2.0 (the
  "License"); you may not use this file except in compliance
  with the License.  You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.
 */
#ifndef JPEG_H
#define JPEG_H

#include <algorithm>

namespace ats
{
namespace inliner
{
  struct JPEG {
    template <class C>
    static bool
    verifySignature(const C &content)
    {
      static const uint32_t SIGNATURE_SIZE = 3;

      static const char SIGNATURE[SIGNATURE_SIZE] = {static_cast<char>(0xff), static_cast<char>(0xd8), static_cast<char>(0xff)};

      return content.size() >= SIGNATURE_SIZE && std::equal(SIGNATURE, SIGNATURE + SIGNATURE_SIZE, content.begin());
    }
  };
} // end of inliner namespace
} // end of ats namespace

#endif // JPEG_H
