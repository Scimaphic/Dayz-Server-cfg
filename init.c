void main()
{
	//INIT WEATHER BEFORE ECONOMY INIT------------------------
	Weather weather = g_Game.GetWeather();

	weather.MissionWeather(false);    // false = use weather controller from Weather.c

	weather.GetOvercast().Set( Math.RandomFloatInclusive(0.4, 0.6), 1, 0);
	weather.GetRain().Set( 0, 0, 1);
	weather.GetFog().Set( Math.RandomFloatInclusive(0.05, 0.1), 1, 0);

	//INIT ECONOMY--------------------------------------
	Hive ce = CreateHive();
	if ( ce )
		ce.InitOffline();

	//DATE RESET AFTER ECONOMY INIT-------------------------
	int year, month, day, hour, minute;
	int reset_month = 9, reset_day = 20;
	GetGame().GetWorld().GetDate(year, month, day, hour, minute);

	if ((month == reset_month) && (day < reset_day))
	{
		GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
	}
	else
	{
		if ((month == reset_month + 1) && (day > reset_day))
		{
			GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
		}
		else
		{
			if ((month < reset_month) || (month > reset_month + 1))
			{
				GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
			}
		}
	}
}

class CustomMission: MissionServer
{
	override PlayerBase CreateCharacter(PlayerIdentity identity, vector pos, ParamsReadContext ctx, string characterName)
	{
		Entity playerEnt = GetGame().CreatePlayer(identity, characterName, pos, 0, "NONE");
		Class.CastTo(m_player, playerEnt);
		GetGame().SelectPlayer(identity, m_player);

		return m_player;
	}


	void addMags(PlayerBase player, string mag_type, int count)
	{
		if (count < 1)
			return;

		EntityAI mag;

		for (int i = 0; i < count; i++) {
			mag = player.GetInventory().CreateInInventory(mag_type);
			//player.SetQuickBarEntityShortcut(mag, i + 1, true);
		}

	}

	EntityAI Assault_1(PlayerBase player)
	{
		EntityAI gun = player.GetHumanInventory().CreateInHands("M4A1_Black");
		gun.GetInventory().CreateAttachment("M4_RISHndgrd_Black");
		gun.GetInventory().CreateAttachment("M4_MPBttstck_Black");
		gun.GetInventory().CreateAttachment("M4_Suppressor");
		gun.GetInventory().CreateAttachment("ACOGOptic");
		player.GetInventory().CreateInInventory("M9A1_Bayonet");
		gun.GetInventory().CreateAttachment("GhillieAtt_Woodland");
		gun.GetInventory().CreateAttachment("Mag_STANAGCoupled_30Rnd");
		addMags(player, "Mag_STANAGCoupled_30Rnd", 4);

		return gun;
	}
	EntityAI Assault_2(PlayerBase player)
	{
		EntityAI gun = player.GetHumanInventory().CreateInHands("AKM");
		gun.GetInventory().CreateAttachment("AK_RailHndgrd_Black");
		gun.GetInventory().CreateAttachment("AK_PlasticBttstck_Black");
		gun.GetInventory().CreateAttachment("AK_Suppressor");
		gun.GetInventory().CreateAttachment("GhillieAtt_Woodland");
		player.GetInventory().CreateInInventory("AK_Bayonet");
		gun.GetInventory().CreateAttachment("Mag_AKM_Drum75Rnd");
		addMags(player, "Mag_AKM_Drum75Rnd", 4);

		return gun;
	}

	EntityAI Shotgun_1(PlayerBase player)
	{
		EntityAI gun = player.GetHumanInventory().CreateInHands("Mp133Shotgun");
		addMags(player, "Ammo_12gaPellets", 8);

		return gun;
	}

	/*
		EntityAI SMG_1(PlayerBase player)
	{
		EntityAI gun = player.GetHumanInventory().CreateInHands("Mp5k");
		addMags(player, "Ammo_12gaPellets", 8);

		return gun;
	}
	*/

	EntityAI Sniper_1(PlayerBase player)
	{
		EntityAI optic_attach
		EntityAI gun = player.GetHumanInventory().CreateInHands("Mosin9130");
		gun.GetInventory().CreateAttachment("Mosin_Compensator");
		player.GetInventory().CreateInInventory("Mosin_Bayonet");
		gun.GetInventory().CreateAttachment("GhillieAtt_Woodland");
		optic_attach = gun.GetInventory().CreateAttachment("PUScopeOptic");
		addMags(player, "Ammo_762x54", 10);
		return gun;
	}
	
	override void StartingEquipSetup(PlayerBase player, bool clothesChosen)
	{
		
		TStringArray clothes = {"HikingJacket_Black","HikingJacket_Red","HikingJacket_Blue","HikingJacket_Green","RidersJacket_Black"};
		TStringArray backpack = {"AliceBag_Black","AssaultBag_Black"};
		TStringArray drink = {"SodaCan_Cola","SodaCan_Kvass","SodaCan_Pipsi","SodaCan_Spite"};
		
		
		player.RemoveAllItems();


		player.GetInventory().CreateInInventory(clothes.GetRandomElement());
		player.GetInventory().CreateInInventory(backpack.GetRandomElement());
		player.GetInventory().CreateInInventory(drink.GetRandomElement());
		player.GetInventory().CreateInInventory(drink.GetRandomElement());
		player.GetInventory().CreateInInventory("TunaCan");
		player.GetInventory().CreateInInventory("TunaCan");
		player.GetInventory().CreateInInventory("Jeans_Black");
		player.GetInventory().CreateInInventory("CombatBoots_Black");
		player.GetInventory().CreateInInventory("HighCapacityVest_Black");
		player.GetInventory().CreateInInventory("PetrolLighter");
		player.GetInventory().CreateInInventory("Rope");
		player.GetInventory().CreateInInventory("NVGHeadstrap");
		player.GetInventory().CreateInInventory("NVGoggles");
        player.GetInventory().CreateInInventory("PersonalRadio");
		player.GetInventory().CreateInInventory("CombatKnife");
		player.GetInventory().CreateInInventory("TacticalGloves_Black");
        player.GetInventory().CreateInInventory("CharcoalTablets");
		player.GetInventory().CreateInInventory("M67Grenade");
		player.GetInventory().CreateInInventory("FlashGrenade");
		player.GetInventory().CreateInInventory("M18SmokeGrenade_White");
		player.GetInventory().CreateInInventory("Battery9V");
		player.GetInventory().CreateInInventory("Battery9V");
		player.GetInventory().CreateInInventory("Battery9V");
		player.GetInventory().CreateInInventory("Battery9V");
		player.GetInventory().CreateInInventory("PainKillerTablets");
		player.GetInventory().CreateInInventory("OrienteeringCompass");
		player.GetInventory().CreateInInventory("BandageDressing");

		EntityAI blt = player.GetInventory().CreateInInventory("MilitaryBelt");
		blt.GetInventory().CreateAttachment("PlateCarrierHolster");
		blt.GetInventory().CreateAttachment("NylonKnifeSheath");
		blt.GetInventory().CreateInInventory("Canteen");

		EntityAI dgl = player.GetInventory().CreateInInventory("Deagle");
		dgl.GetInventory().CreateAttachment("PistolSuppressor");
		dgl.GetInventory().CreateAttachment("PistolOptic");
		dgl.GetInventory().CreateAttachment("Mag_Deagle_9rnd");
		addMags(player,"Mag_Deagle_9rnd",4);

		EntityAI primary;
		EntityAI axe = player.GetInventory().CreateInInventory("FirefighterAxe_Black");
		EntityAI bdg = player.GetInventory().CreateInInventory("BandageDressing");
	
		switch (Math.RandomInt(0, 4)) {
			case 0: primary = Assault_1(player); break;
			case 1: primary = Assault_2(player); break;
			case 2: primary = Shotgun_1(player); break;
			case 3: primary = Sniper_1(player); break;
		}
			
		player.LocalTakeEntityToHands(primary);
		player.SetQuickBarEntityShortcut(primary, 0, true);
		player.SetQuickBarEntityShortcut(dgl, 1, true);
		player.SetQuickBarEntityShortcut(bdg, 3, true);
		player.SetQuickBarEntityShortcut(axe, 2, true);
	}
};

Mission CreateCustomMission(string path)
{
	return new CustomMission();
}