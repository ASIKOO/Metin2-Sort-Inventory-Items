//Find
	for (auto getitem : all) {
		auto table = ITEM_MANAGER::instance().GetTable(getitem->GetVnum());
		if (table && table->dwFlags & ITEM_FLAG_STACKABLE && table->bType != ITEM_BLEND)
			AutoGiveItem(getitem->GetVnum(), getitem->GetCount(), -1, false);
		else
			AutoGiveItem(getitem);
    };
		
///Change
	for (auto getitem : all) {
		auto table = ITEM_MANAGER::instance().GetTable(getitem->GetVnum());
		if (table && table->dwFlags & ITEM_FLAG_STACKABLE && table->bType != ITEM_BLEND)
			AutoGiveItem(getitem->GetVnum(), getitem->GetCount(), -1, false, false);
		else
			AutoGiveItem(getitem, false, false);
    };