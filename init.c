void main()
{
	Hive ce = CreateHive();
	if (ce)
		ce.InitOffline();

	Weather weather = g_Game.GetWeather();

	weather.GetOvercast().SetLimits(0.0, 1.0);
	weather.GetRain().SetLimits(0.0, 1.0);
	weather.GetFog().SetLimits(0.0, 0.25);

	weather.GetOvercast().SetForecastChangeLimits(0.0, 0.2);
	weather.GetRain().SetForecastChangeLimits(0.0, 0.1);
	weather.GetFog().SetForecastChangeLimits(0.15, 0.45);

	weather.GetOvercast().SetForecastTimeLimits(1800, 1800);
	weather.GetRain().SetForecastTimeLimits(600, 600);
	weather.GetFog().SetForecastTimeLimits(1800, 1800);

	weather.GetOvercast().Set(Math.RandomFloatInclusive(0.0, 0.3), 0, 0);
	weather.GetRain().Set(Math.RandomFloatInclusive(0.0, 0.2), 0, 0);
	weather.GetFog().Set(Math.RandomFloatInclusive(0.0, 0.1), 0, 0);

	weather.SetWindMaximumSpeed(15);
	weather.SetWindFunctionParams(0.1, 0.3, 50);
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
			player.SetQuickBarEntityShortcut(mag, i + 1, true);
		}

	}

	EntityAI assault1Class(PlayerBase player)
	{
		EntityAI gun = player.GetHumanInventory().CreateInHands("M4A1_Black");
		gun.GetInventory().CreateAttachment("M4_RISHndgrd_Black");
		gun.GetInventory().CreateAttachment("M4_MPBttstck_Black");
		gun.GetInventory().CreateAttachment("M4_Suppressor");
		gun.GetInventory().CreateAttachment("M4_CarryHandleOptic");
		addMags(player, "Mag_STANAG_30Rnd", 5);

		return gun;
	}
	EntityAI assault2Class(PlayerBase player)
	{
		EntityAI gun = player.GetHumanInventory().CreateInHands("AKM");
		gun.GetInventory().CreateAttachment("AK_WoodBttstck");
		gun.GetInventory().CreateAttachment("AK_WoodHndgrd");
		addMags(player, "Mag_AKM_Drum75Rnd", 4);

		return gun;
	}

	EntityAI shotgunClass(PlayerBase player)
	{
		EntityAI gun = player.GetHumanInventory().CreateInHands("Mp133Shotgun");
		addMags(player, "AmmoBox_12gaSlug_10Rnd", 5);

		return gun;
	}

	/*
	EntityAI smgClass(PlayerBase player)
	{
		EntityAI optic_attach
		EntityAI gun = player.GetHumanInventory().CreateInHands("UMP45");
		gun.GetInventory().CreateAttachment("PistolSuppressor");
		optic_attach = gun.GetInventory().CreateAttachment("M68Optic");
	    optic_attach.GetInventory().CreateAttachment( "Battery9V" );
		gun.GetInventory().CreateAttachment("PistolSuppressor");
        addMags(player, "Mag_UMP_25Rnd", 4);

		return gun;
	}
	*/
	
	override void StartingEquipSetup(PlayerBase player, bool clothesChosen)
	{
		//
		TStringArray pants = {"Jeans_Black"};
		TStringArray shoes = {"CombatBoots_Black"};
		TStringArray yifu = {"HikingJacket_Black","HikingJacket_Red","HikingJacket_Blue","HikingJacket_Green"};
		TStringArray backpack = {"AliceBag_Black"};
      		TStringArray vest = {"HighCapacityVest_Black"};
		TStringArray drink = {"SodaCan_Cola","SodaCan_Kvass","SodaCan_Pipsi","SodaCan_Spite"};
       		TStringArray food = {"Rice","SmallGuts","PowderedMilk","PeachesCan","Pear"};
		TStringArray tool = {"CombatKnife","PurificationTablets","Matchbox"};
		//
		
		player.RemoveAllItems();
		
		player.GetInventory().CreateInInventory(pants.GetRandomElement());
		player.GetInventory().CreateInInventory(shoes.GetRandomElement());
		player.GetInventory().CreateInInventory(yifu.GetRandomElement());
		player.GetInventory().CreateInInventory(backpack.GetRandomElement());
		player.GetInventory().CreateInInventory(vest.GetRandomElement());
		player.GetInventory().CreateInInventory(drink.GetRandomElement());
		player.GetInventory().CreateInInventory(food.GetRandomElement());
		player.GetInventory().CreateInInventory(drink.GetRandomElement());
		player.GetInventory().CreateInInventory(food.GetRandomElement());
		player.GetInventory().CreateInInventory(tool.GetRandomElement());
		player.GetInventory().CreateInInventory("CanOpener");
        player.GetInventory().CreateInInventory("PersonalRadio");
		player.GetInventory().CreateInInventory("MilitaryBelt");
		player.GetInventory().CreateInInventory("NylonKnifeSheath");
		player.GetInventory().CreateInInventory("TacticalGloves_Black");
		player.GetInventory().CreateInInventory("M67Grenade");
        player.GetInventory().CreateInInventory("Battery9V");
		player.GetInventory().CreateInInventory("Battery9V");
        player.GetInventory().CreateInInventory("AmmoBox_45ACP_25rnd");
		player.GetInventory().CreateInInventory("AmmoBox_45ACP_25rnd");
		player.GetInventory().CreateInInventory("AmmoBox_45ACP_25rnd");
		player.GetInventory().CreateInInventory("AmmoBox_45ACP_25rnd");
		player.GetInventory().CreateInInventory("PistolSuppressor");
		player.GetInventory().CreateInInventory("Canteen");
		player.GetInventory().CreateInInventory("OrienteeringCompass");
		player.GetInventory().CreateInInventory("FNX45");
		ItemBase rags = player.GetInventory().CreateInInventory("Rag");
		rags.SetQuantity(4);
		addMags(player, "Mag_FNX45_15Rnd", 3);

		EntityAI primary;
		EntityAI axe = player.GetInventory().CreateInInventory("FirefighterAxe_Black");
	
		switch (Math.RandomInt(0, 4)) {
			case 0: primary = assault1Class(player); break;
			case 1: primary = assault2Class(player); break;
			case 2: primary = shotgunClass(player); break;
			//case 3: primary = smgClass(player); break;
		}
			
		player.LocalTakeEntityToHands(primary);
		player.SetQuickBarEntityShortcut(primary, 0, true);
		player.SetQuickBarEntityShortcut(rags, 4, true);
		player.SetQuickBarEntityShortcut(axe, 5, true);
	}
};

Mission CreateCustomMission(string path)
{
	return new CustomMission();
}