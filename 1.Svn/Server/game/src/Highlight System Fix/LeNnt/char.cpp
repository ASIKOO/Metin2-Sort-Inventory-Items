//Find
		if (item) {
			TItemTable * p = ITEM_MANAGER::instance().GetTable(item->GetVnum());
			/// isn't same function !
			if (p && p->dwFlags & ITEM_FLAG_STACKABLE && p->bType != ITEM_BLEND)
				AutoGiveItem(item->GetVnum(), item->GetCount(), -1, false); // create new item for stackable items + msg bug fixed
			else
				AutoGiveItem(item); // copy orginal items
		}
		
///Change
		if (item) {
			TItemTable * p = ITEM_MANAGER::instance().GetTable(item->GetVnum());
			/// isn't same function !
			if (p && p->dwFlags & ITEM_FLAG_STACKABLE && p->bType != ITEM_BLEND)
				AutoGiveItem(item->GetVnum(), item->GetCount(), -1, false, false); // create new item for stackable items + msg bug fixed
			else
				AutoGiveItem(item, false, false); // copy orginal items
		}