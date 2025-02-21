/*
 * DBActiveSessionsStorage.hpp
 *
 * Copyright (C) 2022 by RStudio, PBC
 *
 * Unless you have received this program directly from RStudio pursuant
 * to the terms of a commercial license agreement with RStudio, then
 * this program is licensed to you under the terms of version 3 of the
 * GNU Affero General Public License. This program is distributed WITHOUT
 * ANY EXPRESS OR IMPLIED WARRANTY, INCLUDING THOSE OF NON-INFRINGEMENT,
 * MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE. Please refer to the
 * AGPL (http://www.gnu.org/licenses/agpl-3.0.txt) for more details.
 *
 */

#ifndef DB_ACTIVE_SESSIONS_STORAGE_HPP
#define DB_ACTIVE_SESSIONS_STORAGE_HPP

#include <core/r_util/RActiveSessions.hpp>
#include <core/r_util/RActiveSessionsStorage.hpp>

#include <shared_core/Error.hpp>
#include <shared_core/FilePath.hpp>

namespace rstudio {
namespace server {
namespace storage {

using namespace core;
using namespace core::r_util;

class DBActiveSessionsStorage : public IActiveSessionsStorage
{
public:
   explicit DBActiveSessionsStorage(const std::string& userId, const FilePath& rootStoragePath);
   ~DBActiveSessionsStorage() = default;
   core::Error initSessionProperties(const std::string& id, std::map<std::string, std::string> initialProperties) override;
   std::vector< std::string > listSessionIds() const override;
   size_t getSessionCount() const override;
   std::shared_ptr<IActiveSessionStorage> getSessionStorage(const std::string& id) const override;
   bool hasSessionId(const std::string& sessionId) const override;
private:
   std::string userId_;
   FilePath rootStoragePath_;
};

} // namespace storage
} // namespace server
} // namespace rstudio

#endif
