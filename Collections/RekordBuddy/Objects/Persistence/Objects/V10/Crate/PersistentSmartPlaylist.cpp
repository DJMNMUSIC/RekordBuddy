//
//  Rekord Buddy - The future proof music collection tool made by DJs for DJs.
//  Copyright (C) 2020-2021 Didier Malenfant (didier@rekordbuddy.org)
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <https://www.gnu.org/licenses/>.
//

#include <RekordBuddyCollectionImplementationPersistence/V10/Crate/PersistentSmartPlaylist.hpp>

#include <RekordBuddyCollectionImplementationPersistence/V10/Crate/PersistentFilterPlaylist.hpp>
using namespace NxA;

using namespace NxA::RekordBuddy::CollectionImplementation::V10;

using LocalType = PersistentSmartPlaylist;

template class std::shared_ptr<PersistentSmartPlaylist>;

template class NxA::Array<std::shared_ptr<PersistentSmartPlaylist>>;
void PersistentSmartPlaylist::bind(SourceBinder& parentBinder)
{
    PersistentFilterPlaylist::bind(parentBinder);
    parentBinder.bind(RBSchema::Type::SmartPlaylist, RBSchema::Type::FilterPlaylist);
}
void PersistentSmartPlaylist::faultObject()
{
    if (isFaulted()) {
        return;
    }
    PersistentFilterPlaylist::faultObject();
}
void PersistentSmartPlaylist::deleteObject()
{
    if (isDeleted()) {
        return;
    }
    PersistentFilterPlaylist::deleteObject();
}


