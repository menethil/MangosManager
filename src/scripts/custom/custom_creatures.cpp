/* Copyright (C) 2009 - 2010 ScriptDevZero <http://github.com/scriptdevzero/scriptdevzero>
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "scriptPCH.h"
#include "custom.h"
#include "ScriptedAI.h"
#include <ctime>

 // TELEPORT NPC

bool GossipHello_TeleportNPC(Player *player, Creature *_Creature)
{
	// HORDE
	if (player->GetTeam() == HORDE)
	{
		// player->ADD_GOSSIP_ITEM(5, "PreTBC Mall"          , GOSSIP_SENDER_MAIN, 74);
		player->ADD_GOSSIP_ITEM(5, " 主城 ", GOSSIP_SENDER_MAIN, 1);
		player->ADD_GOSSIP_ITEM(5, " 出生地 ", GOSSIP_SENDER_MAIN, 3);
		player->ADD_GOSSIP_ITEM(5, " 副本 ", GOSSIP_SENDER_MAIN, 5);
		player->ADD_GOSSIP_ITEM(5, " 团队副本 ", GOSSIP_SENDER_MAIN, 101);
		player->ADD_GOSSIP_ITEM(5, " 古拉巴什竞技场 ", GOSSIP_SENDER_MAIN, 4015);
		player->ADD_GOSSIP_ITEM(5, " 地区 - 卡里姆多 ", GOSSIP_SENDER_MAIN, 6010);
		player->ADD_GOSSIP_ITEM(5, " 地区 - 东部王国 ", GOSSIP_SENDER_MAIN, 6020);

		player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
	}
	// ALLIANCE
	else
	{
		//player->ADD_GOSSIP_ITEM(5, "PreTBC Mall"          , GOSSIP_SENDER_MAIN, 74);
		player->ADD_GOSSIP_ITEM(5, " 主城 ", GOSSIP_SENDER_MAIN, 2);
		player->ADD_GOSSIP_ITEM(5, " 出生地 ", GOSSIP_SENDER_MAIN, 4);
		player->ADD_GOSSIP_ITEM(5, " 副本 ", GOSSIP_SENDER_MAIN, 5);
		player->ADD_GOSSIP_ITEM(5, " 团队副本 ", GOSSIP_SENDER_MAIN, 101);
		player->ADD_GOSSIP_ITEM(5, " 古拉巴什竞技场 ", GOSSIP_SENDER_MAIN, 4015);
		player->ADD_GOSSIP_ITEM(5, " 地区 - 卡里姆多 ", GOSSIP_SENDER_MAIN, 6010);
		player->ADD_GOSSIP_ITEM(5, " 地区 - 东部王国 ", GOSSIP_SENDER_MAIN, 6020);

		player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
	}
	return true;
}

void SendDefaultMenu_TeleportNPC(Player *player, Creature *_Creature, uint32 action)
{
	switch (action)
	{
	case 1: // Cities [HORDE]
		player->ADD_GOSSIP_ITEM(5, " 奥格瑞玛 ", GOSSIP_SENDER_MAIN, 20);
		player->ADD_GOSSIP_ITEM(5, " 幽暗城 ", GOSSIP_SENDER_MAIN, 21);
		player->ADD_GOSSIP_ITEM(5, " 雷霆崖 ", GOSSIP_SENDER_MAIN, 22);
		//player->ADD_GOSSIP_ITEM(5, "Goldshire (Stormwind)" , GOSSIP_SENDER_MAIN, 4018);
		player->ADD_GOSSIP_ITEM(5, "<-[ 主菜单 ]", GOSSIP_SENDER_MAIN, 100);

		player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
		break;
	case 2: // Cities [ALLIANCE]
		player->ADD_GOSSIP_ITEM(5, " 暴风城 ", GOSSIP_SENDER_MAIN, 23);
		player->ADD_GOSSIP_ITEM(5, " 铁炉堡 ", GOSSIP_SENDER_MAIN, 24);
		player->ADD_GOSSIP_ITEM(5, " 达纳苏斯 ", GOSSIP_SENDER_MAIN, 25);
		//player->ADD_GOSSIP_ITEM(5, "Razor Hill(奥格瑞玛)" , GOSSIP_SENDER_MAIN, 4017);
		player->ADD_GOSSIP_ITEM(5, "<-[ 主菜单 ]", GOSSIP_SENDER_MAIN, 100);

		player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
		break;
	case 3: // Starting Places [HORDE]
		player->ADD_GOSSIP_ITEM(5, " 丧钟镇 ", GOSSIP_SENDER_MAIN, 40);
		player->ADD_GOSSIP_ITEM(5, " 试练谷 ", GOSSIP_SENDER_MAIN, 41);
		player->ADD_GOSSIP_ITEM(5, " 莫高雷 ", GOSSIP_SENDER_MAIN, 42);
		player->ADD_GOSSIP_ITEM(5, "<-[ 主菜单 ]", GOSSIP_SENDER_MAIN, 100);

		player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
		break;
	case 4: // Starting Places [ALLIANCE]
		player->ADD_GOSSIP_ITEM(5, " 北郡修道院 ", GOSSIP_SENDER_MAIN, 43);
		player->ADD_GOSSIP_ITEM(5, " 寒脊山谷 ", GOSSIP_SENDER_MAIN, 44);
		player->ADD_GOSSIP_ITEM(5, " 泰达希尔 ", GOSSIP_SENDER_MAIN, 45);
		player->ADD_GOSSIP_ITEM(5, "<-[ 主菜单 ]", GOSSIP_SENDER_MAIN, 100);

		player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
		break;
	case 5: // Instances [PAGE 1]
		player->ADD_GOSSIP_ITEM(5, " 哀嚎洞穴 ", GOSSIP_SENDER_MAIN, 1249);
		player->ADD_GOSSIP_ITEM(5, " 死亡矿井 ", GOSSIP_SENDER_MAIN, 1250);
		player->ADD_GOSSIP_ITEM(5, " 影牙城堡 ", GOSSIP_SENDER_MAIN, 1251);
		player->ADD_GOSSIP_ITEM(5, " 黑暗深渊 ", GOSSIP_SENDER_MAIN, 1252);
		player->ADD_GOSSIP_ITEM(5, " 剃刀沼泽 ", GOSSIP_SENDER_MAIN, 1254);
		player->ADD_GOSSIP_ITEM(5, " 剃刀高地 ", GOSSIP_SENDER_MAIN, 1256);
		player->ADD_GOSSIP_ITEM(5, " 血色修道院 ", GOSSIP_SENDER_MAIN, 1257);
		player->ADD_GOSSIP_ITEM(7, "[ 更多 ] ->", GOSSIP_SENDER_MAIN, 5551);
		player->ADD_GOSSIP_ITEM(5, "<-[ 主菜单 ]", GOSSIP_SENDER_MAIN, 100);

		player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
		break;
	case 5551: // Instances [PAGE 2]
		player->ADD_GOSSIP_ITEM(5, " 奥达曼 ", GOSSIP_SENDER_MAIN, 1258);
		player->ADD_GOSSIP_ITEM(5, " 祖尔法拉克 ", GOSSIP_SENDER_MAIN, 1259);
		player->ADD_GOSSIP_ITEM(5, " 玛拉顿 ", GOSSIP_SENDER_MAIN, 1260);
		player->ADD_GOSSIP_ITEM(5, " 沉没的神殿 ", GOSSIP_SENDER_MAIN, 1261);
		player->ADD_GOSSIP_ITEM(5, " 黑石深渊 ", GOSSIP_SENDER_MAIN, 1262);
		player->ADD_GOSSIP_ITEM(5, " 厄运之槌 ", GOSSIP_SENDER_MAIN, 1263);
		player->ADD_GOSSIP_ITEM(5, " 黑石塔 ", GOSSIP_SENDER_MAIN, 1264);
		player->ADD_GOSSIP_ITEM(5, " 斯坦索姆 ", GOSSIP_SENDER_MAIN, 1265);
		player->ADD_GOSSIP_ITEM(5, " 通灵学院 ", GOSSIP_SENDER_MAIN, 1266);
		player->ADD_GOSSIP_ITEM(7, "<- [ 返回 ]", GOSSIP_SENDER_MAIN, 5);
		player->ADD_GOSSIP_ITEM(5, "<-[ 主菜单 ]", GOSSIP_SENDER_MAIN, 100);

		player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
		break;
	case 101: // 团队副本
		player->ADD_GOSSIP_ITEM(5, " 祖尔格拉布 ", GOSSIP_SENDER_MAIN, 4000);
		player->ADD_GOSSIP_ITEM(5, " 奥尼克希娅的巢穴 ", GOSSIP_SENDER_MAIN, 4001);
		player->ADD_GOSSIP_ITEM(5, " 熔火之心 ", GOSSIP_SENDER_MAIN, 4002);
		player->ADD_GOSSIP_ITEM(5, " 黑翼之巢 ", GOSSIP_SENDER_MAIN, 4003);
		player->ADD_GOSSIP_ITEM(5, " 安其拉废墟 ", GOSSIP_SENDER_MAIN, 4004);
		player->ADD_GOSSIP_ITEM(5, " 安其拉神庙 ", GOSSIP_SENDER_MAIN, 4005);
		player->ADD_GOSSIP_ITEM(5, " 纳克萨玛斯 ", GOSSIP_SENDER_MAIN, 4006);
		player->ADD_GOSSIP_ITEM(5, "<-[ 主菜单 ]", GOSSIP_SENDER_MAIN, 100);

		player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
		break;
	case 6010: // Kalimdor
		player->ADD_GOSSIP_ITEM(5, " 灰谷 ", GOSSIP_SENDER_MAIN, 601);
		player->ADD_GOSSIP_ITEM(5, " 黑海岸 ", GOSSIP_SENDER_MAIN, 602);
		player->ADD_GOSSIP_ITEM(5, " 凄凉之地 ", GOSSIP_SENDER_MAIN, 603);
		player->ADD_GOSSIP_ITEM(5, " 杜隆塔尔 ", GOSSIP_SENDER_MAIN, 604);
		player->ADD_GOSSIP_ITEM(5, " 尘泥沼泽 ", GOSSIP_SENDER_MAIN, 605);
		player->ADD_GOSSIP_ITEM(5, " 菲拉斯 ", GOSSIP_SENDER_MAIN, 606);
		player->ADD_GOSSIP_ITEM(5, " 希利苏斯 ", GOSSIP_SENDER_MAIN, 607);
		player->ADD_GOSSIP_ITEM(5, " 石爪山脉 ", GOSSIP_SENDER_MAIN, 608);
		player->ADD_GOSSIP_ITEM(5, " 塔纳利斯 ", GOSSIP_SENDER_MAIN, 609);
		player->ADD_GOSSIP_ITEM(5, " 贫瘠之地 ", GOSSIP_SENDER_MAIN, 610);
		player->ADD_GOSSIP_ITEM(5, " 千针石林 ", GOSSIP_SENDER_MAIN, 611);
		player->ADD_GOSSIP_ITEM(5, " 冬泉谷 ", GOSSIP_SENDER_MAIN, 612);
		player->ADD_GOSSIP_ITEM(5, "<-[ 主菜单 ]", GOSSIP_SENDER_MAIN, 100);

		player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
		break;
	case 6020: // Eastern Kingdoms
		player->ADD_GOSSIP_ITEM(5, " 阿拉希高地 ", GOSSIP_SENDER_MAIN, 613);
		player->ADD_GOSSIP_ITEM(5, " 荒芜之地 ", GOSSIP_SENDER_MAIN, 614);
		player->ADD_GOSSIP_ITEM(5, " 丹莫罗 ", GOSSIP_SENDER_MAIN, 615);
		player->ADD_GOSSIP_ITEM(5, " 暮色森林 ", GOSSIP_SENDER_MAIN, 616);
		player->ADD_GOSSIP_ITEM(5, " 东瘟疫之地 ", GOSSIP_SENDER_MAIN, 617);
		player->ADD_GOSSIP_ITEM(5, " 艾尔文森林 ", GOSSIP_SENDER_MAIN, 618);
		player->ADD_GOSSIP_ITEM(5, " 希尔斯布莱德丘陵 ", GOSSIP_SENDER_MAIN, 619);
		player->ADD_GOSSIP_ITEM(5, " 赤脊山 ", GOSSIP_SENDER_MAIN, 620);
		player->ADD_GOSSIP_ITEM(5, " 银松森林 ", GOSSIP_SENDER_MAIN, 621);
		player->ADD_GOSSIP_ITEM(5, " 荆棘谷 ", GOSSIP_SENDER_MAIN, 622);
		player->ADD_GOSSIP_ITEM(5, " 悲伤沼泽 ", GOSSIP_SENDER_MAIN, 623);
		player->ADD_GOSSIP_ITEM(5, " 辛特兰 ", GOSSIP_SENDER_MAIN, 624);
		player->ADD_GOSSIP_ITEM(5, " 提瑞斯法林地 ", GOSSIP_SENDER_MAIN, 625);
		player->ADD_GOSSIP_ITEM(5, " 西部荒野 ", GOSSIP_SENDER_MAIN, 626);
		player->ADD_GOSSIP_ITEM(5, " 湿地 ", GOSSIP_SENDER_MAIN, 627);
		player->ADD_GOSSIP_ITEM(5, "<-[ 主菜单 ]", GOSSIP_SENDER_MAIN, 100);

		player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
		break;



		// ----### CITIES ###----

		// ### HORDE ###

	case 20: // 奥格瑞玛
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(1, 1437.0f, -4421.0f, 25.24f, 1.65f);
		break;
	case 21: // 幽暗城
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(0, 1822.0999f, 238.638855f, 60.694809f, 0.0f);
		break;
	case 22: // 雷霆崖
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(1, -1272.703735f, 116.886490f, 131.016861f, 0.0f);
		break;

		// ### ALLIANCE ###

	case 23: // Stormwind
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(0, -8828.231445f, 627.927490f, 94.055664f, 0.0f);
		break;
	case 24: // 铁炉堡
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(0, -4917.0f, -955.0f, 502.0f, 0.0f);
		break;
	case 25: // 达纳苏斯
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(1, 9962.712891f, 2280.142822f, 1341.394409f, 0.0f);
		break;

		// ----### STARTING PLACES ####----

		// ### HORDE ###
	case 40: // 丧钟镇
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(0, 1663.517f, 1678.187744f, 120.5303f, 0.0f);
		break;
	case 41: // 试练谷
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(1, -602.1253f, -4262.4208f, 38.956341f, 0.0f);
		break;
	case 42: // 莫高雷
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(1, -2914.16992f, -266.061798f, 53.658211f, 0.0f);
		break;

		// ### ALLIANCE ###

	case 43: // Nortshire Valley
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(0, -8943.133789f, -132.934921f, 83.704269f, 0.0f);
		break;
	case 44: // 寒脊山谷
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(0, -6231.106445f, 332.270477f, 383.153931f, 0.0f);
		break;
	case 45: // 泰达希尔
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(1, 10329.918945f, 833.500305f, 1326.260620f, 0.0f);
		break;

		// ----### INSTANCES ###----

	case 50: // Dire Maul
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(1, -3762.340820f, 1216.537598f, 127.434608f, 0.0f);
		break;
	case 51: // Blackrock Spire
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(0, -7528.554688f, -1222.907227f, 285.732941f, 0.0f);
		break;
	case 52: // 祖尔格拉布
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(0, -11916.179688f, -1190.977051f, 85.137901f, 0.0f);
		break;
	case 53: // 奥尼克希娅的巢穴
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(1, -4682.391602f, -3709.857422f, 46.792862f, 0.0f);
		break;
	case 54: // Searing Gorge (Moltencore, Blackwinglair)
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(0, -7342.270020f, -1096.863892f, 277.06930f, 0.0f);
		break;
	case 55: // 纳克萨玛斯
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(0, 3121.061768f, -3689.973389f, 133.458786f, 0.0f);
		break;
	case 56: // Stratholme Backdoor Entrance
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(0, 3160.416992f, -4038.750244f, 104.177376f, 0.0f);
		break;
	case 57: // Stratholme Main Entrance
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(0, 3357.214355f, -3379.713135f, 144.780853f, 0.0f);
		break;
	case 58: // Scholomance
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(0, 1252.319824f, -2587.151123f, 92.886772f, 0.0f);
		break;

		// ---### ZONES ###---

	case 70: // 希利苏斯
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(1, -7430.070313f, 1002.554565f, 1.249787f, 0.0f);
		break;
	case 71: // 杜隆塔尔
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(1, 1006.426819f, -4439.258789f, 11.352882f, 0.0f);
		break;
	case 72: // Ashenvale
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(1, 1922.842651f, -2169.429688f, 94.327400f, 0.0f);
		break;
	case 73: // 塔纳利斯
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(1, -7180.401367f, -3773.328369f, 8.728320f, 0.0f);
		break;
	case 74: // Pretbc Mall
		//player->CLOSE_GOSSIP_MENU();
		//player->TeleportTo(1, 16201.107422f, 16205.1875f, 0.140072f, 1.630427f);
		break;
	case 4015:// Gurubashi
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(0, -13261.3f, 168.294f, 35.0792f, 1.00688f);
		break;
	case 4017:// Razor Hill
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(1, 315.721f, -4743.4f, 10.4867f, 0.0f);
		break;
	case 4018:// Goldshire
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(0, -9464.0f, 62.0f, 56.0f, 0.0f);
		break;
	case 1249://teleport player to the Wailing Caverns
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(1, -722.53f, -2226.30f, 16.94f, 2.71f);
		break;
	case 1250://teleport player to the Deadmines
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(0, -11212.04f, 1658.58f, 25.67f, 1.45f);
		break;
	case 1251://teleport player to Shadowfang Keep
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(0, -254.47f, 1524.68f, 76.89f, 1.56f);
		break;
	case 1252://teleport player to Blackfathom Deeps
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(1, 4254.58f, 664.74f, -29.04f, 1.97f);
		break;
	case 1254://teleport player to Razorfen Kraul
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(1, -4484.04f, -1739.40f, 86.47f, 1.23f);
		break;
	case 1256://teleport player to Razorfen Downs
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(1, -4645.08f, -2470.85f, 85.53f, 4.39f);
		break;
	case 1257://teleport player to the Scarlet Monastery
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(0, 2843.89f, -693.74f, 139.32f, 5.11f);
		break;
	case 1258://teleport player to Uldaman
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(0, -6119.70f, -2957.30f, 204.11f, 0.03f);
		break;
	case 1259://teleport player to Zul'Farrak
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(1, -6839.39f, -2911.03f, 8.87f, 0.41f);
		break;
	case 1260://teleport player to Maraudon
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(1, -1433.33f, 2955.34f, 96.21f, 4.82f);
		break;
	case 1261://teleport player to the Sunken Temple
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(0, -10346.92f, -3851.90f, -43.41f, 6.09f);
		break;
	case 1262://teleport player to Blackrock Depths
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(0, -7301.03f, -913.19f, 165.37f, 0.08f);
		break;
	case 1263://teleport player to Dire Maul
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(1, -3982.47f, 1127.79f, 161.02f, 0.05f);
		break;
	case 1264://teleport player to Blackrock Spire
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(0, -7535.43f, -1212.04f, 285.45f, 5.29f);
		break;
	case 1265://teleport player to Stratholme
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(0, 3263.54f, -3379.46f, 143.59f, 0.00f);
		break;
	case 1266://teleport player to Scholomance
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(0, 1219.01f, -2604.66f, 85.61f, 0.50f);
		break;
	case 4000:// Teleport to 祖尔格拉布
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(0, -11916.7f, -1212.82f, 92.2868f, 4.6095f);
		break;
	case 4001:// Teleport to 奥尼克希娅的巢穴
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(1, -4707.44f, -3726.82f, 54.6723f, 3.8f);
		break;
	case 4002:// Teleport to 熔火之心
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(230, 1121.451172f, -454.316772f, -101.329536f, 3.5f);
		break;
	case 4003:// Teleport to 黑翼之巢
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(469, -7665.55f, -1102.49f, 400.679f, 0.0f);
		break;
	case 4004:// 安其拉废墟
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(1, -8409.032227f, 1498.830933f, 27.361542f, 2.497567f);
		break;
	case 4005:// 安其拉神庙
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(1, -8245.837891f, 1983.736206f, 129.071686f, 0.936195f);
		break;
	case 4006:// 纳克萨玛斯
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(533, 3005.87f, -3435.0f, 293.89f, 0.0f);
		break;
	case 601: // Kalimdor -> Ashenvale
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(1, 3469.43f, 847.62f, 6.36476f, 0.0f);
		break;
	case 602: // Kalimdor -> Darkshore
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(1, 6207.5f, -152.833f, 80.8185f, 0.0f);
		break;
	case 603: // Kalimdor -> Desolace
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(1, -93.1614f, 1691.15f, 90.0649f, 0.0f);
		break;
	case 604: // Kalimdor -> 杜隆塔尔
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(1, 341.42f, -4684.7f, 31.9493f, 0.0f);
		break;
	case 605: // Kalimdor -> Duswallow Marsh
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(1, -3463.26f, -4123.13f, 18.1043f, 0.0f);
		break;
	case 606: // Kalimdor -> Ferelas
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(1, -4458.93f, 243.415f, 65.6136f, 0.0f);
		break;
	case 607: // Kalimdor -> 希利苏斯
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(1, -6824.15f, 821.273f, 50.6675f, 0.0f);
		break;
	case 608: // Kalimdor -> 石爪山脉
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(1, 1145.00f, 85.664f, -6.64f, 0.0f);
		break;
	case 609: // Kalimdor -> 塔纳利斯
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(1, -7373.69f, -2950.2f, 11.7598f, 0.0f);
		break;
	case 610: // Kalimdor -> 贫瘠之地
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(1, -456.263f, -2652.7f, 96.615f, 0.0f);
		break;
	case 611: // Kalimdor -> 千针石林
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(1, -4941.66f, -1595.42f, -33.07f, 0.0f);
		break;
	case 612: // Kalimdor -> 冬泉谷
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(1, 6107.62f, -4181.6f, 853.322f, 0.0f);
		break;
	case 613: // Eastern Kingdoms -> 阿拉希高地
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(0, -1544.93f, -2495.01f, 54.11f, 0.0f);
		break;
	case 614: // Eastern Kingdoms -> 荒芜之地
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(0, -6084.95f, -3328.44f, 253.76f, 0.0f);
		break;
	case 615: // Eastern Kingdoms -> 丹莫罗
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(0, -5660.33f, 755.299f, 390.605f, 0.0f);
		break;
	case 616: // Eastern Kingdoms -> 暮色森林
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(0, -10879.85f, -327.06f, 37.78f, 0.0f);
		break;
	case 617: // Eastern Kingdoms -> 东瘟疫之地
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(0, 2280.12f, -5313.16f, 87.74f, 0.0f);
		break;
	case 618: // Eastern Kingdoms -> 艾尔文森林
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(0, -9545.78f, -51.81f, 56.72f, 0.0f);
		break;
	case 619: // Eastern Kingdoms -> 希尔斯布莱德丘陵
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(0, -436.03f, -583.27f, 53.58f, 0.0f);
		break;
	case 620: // Eastern Kingdoms -> 赤脊山脉
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(0, -9633.80f, -1875.09f, 68.39f, 0.0f);
		break;
	case 621: // Eastern Kingdoms -> 银松森林
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(0, 641.48f, 1297.84f, 85.45f, 0.0f);
		break;
	case 622: // Eastern Kingdoms -> 荆棘谷
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(0, -11393.77f, -288.94f, 58.99f, 0.0f);
		break;
	case 623: // Eastern Kingdoms -> 悲伤沼泽
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(0, -10522.55f, -3028.30f, 21.79f, 0.0f);
		break;
	case 624: // Eastern Kingdoms -> 辛特兰
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(0, 155.14f, -2014.95f, 122.55f, 0.0f);
		break;
	case 625: // Eastern Kingdoms -> 提瑞斯法林地
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(0, 2255.5f, 288.511f, 35.1138f, 0.0f);
		break;
	case 626: // Eastern Kingdoms -> 西部荒野
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(0, -10919.09f, 998.47f, 35.47f, 0.0f);
		break;
	case 627: // Eastern Kingdoms -> 湿地
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(0, -4086.36f, -2610.95f, 47.0143f, 0.0f);
		break;

	case 100: // Main Menu
		// HORDE
		if (player->GetTeam() == HORDE)
		{
			//player->ADD_GOSSIP_ITEM(5, "PreTBC Mall"          , GOSSIP_SENDER_MAIN, 74);
			player->ADD_GOSSIP_ITEM(5, " 主城 ", GOSSIP_SENDER_MAIN, 1);
			player->ADD_GOSSIP_ITEM(5, " 出生地 ", GOSSIP_SENDER_MAIN, 3);
			player->ADD_GOSSIP_ITEM(5, " 副本 ", GOSSIP_SENDER_MAIN, 5);
			player->ADD_GOSSIP_ITEM(5, " 团队副本 ", GOSSIP_SENDER_MAIN, 101);
			player->ADD_GOSSIP_ITEM(5, " 古拉巴什竞技场 ", GOSSIP_SENDER_MAIN, 4015);
			player->ADD_GOSSIP_ITEM(5, " 地区 - 卡里姆多 ", GOSSIP_SENDER_MAIN, 6010);
			player->ADD_GOSSIP_ITEM(5, " 地区 - 东部王国 ", GOSSIP_SENDER_MAIN, 6020);

			player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
		}
		// ALLIANCE
		else
		{
			//player->ADD_GOSSIP_ITEM(5, "PreTBC Mall"          , GOSSIP_SENDER_MAIN, 74);
			player->ADD_GOSSIP_ITEM(5, " 主城 ", GOSSIP_SENDER_MAIN, 2);
			player->ADD_GOSSIP_ITEM(5, " 出生地 ", GOSSIP_SENDER_MAIN, 4);
			player->ADD_GOSSIP_ITEM(5, " 副本 ", GOSSIP_SENDER_MAIN, 5);
			player->ADD_GOSSIP_ITEM(5, " 团队副本 ", GOSSIP_SENDER_MAIN, 101);
			player->ADD_GOSSIP_ITEM(5, " 古拉巴什竞技场 ", GOSSIP_SENDER_MAIN, 4015);
			player->ADD_GOSSIP_ITEM(5, " 地区 - 卡里姆多 ", GOSSIP_SENDER_MAIN, 6010);
			player->ADD_GOSSIP_ITEM(5, " 地区 - 东部王国 ", GOSSIP_SENDER_MAIN, 6020);

			player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
		}
		break;
	}
}
bool GossipSelect_TeleportNPC(Player *player, Creature *_Creature, uint32 sender, uint32 action)
{
	// Main menu
	if (sender == GOSSIP_SENDER_MAIN)
		SendDefaultMenu_TeleportNPC(player, _Creature, action);

	return true;
}

enum Enchants
{
	WEP2H_SUPERIOR_IMPACT = 20,
	WEP2H_AGILITY,
	WEP_CRUSADER,
	WEP1H_AGILITY,
	WEP_SPELLPOWER,
	WEP_HEAL,
	OFFHAND_SPIRIT,
	OFFHAND_STAM,
	OFFHAND_FROSTRES,
	CHEST_STATS,
	CLOAK_DODGE,
	CLOAK_SUB,
	CLOAK_ARMOR,
	CLOAK_AGILITY,
	BRACER_STAM,
	BRACER_STR,
	BRACER_HEAL,
	BRACER_INT,
	GLOVES_AGI,
	GLOVES_FIRE,
	GLOVES_FROST,
	GLOVES_SHADOW,
	GLOVES_HEALING,
	BOOTS_AGI,
	BOOTS_SPEED,
	BOOTS_STAM,
};

void Enchant(Player* player, Item* item, uint32 enchantid)
{
	if (!item)
	{
		player->GetSession()->SendNotification(" 你必须先装备物品. ");
		return;
	}

	if (!enchantid)
	{
		player->GetSession()->SendNotification(" 呃，似乎发生了点错误. ");
		return;
	}

	item->ClearEnchantment(PERM_ENCHANTMENT_SLOT);
	item->SetEnchantment(PERM_ENCHANTMENT_SLOT, enchantid, 0, 0);
	player->GetSession()->SendNotification(" %s 附魔完成. ", item->GetProto()->Name1);
}

bool GossipHello_EnchantNPC(Player* player, Creature* creature)
{

	player->ADD_GOSSIP_ITEM(5, " 胸甲 ", GOSSIP_SENDER_MAIN, EQUIPMENT_SLOT_CHEST);
	player->ADD_GOSSIP_ITEM(5, " 披风 ", GOSSIP_SENDER_MAIN, EQUIPMENT_SLOT_BACK);
	player->ADD_GOSSIP_ITEM(5, " 护腕 ", GOSSIP_SENDER_MAIN, EQUIPMENT_SLOT_WRISTS);
	player->ADD_GOSSIP_ITEM(5, " 手套 ", GOSSIP_SENDER_MAIN, EQUIPMENT_SLOT_HANDS);
	player->ADD_GOSSIP_ITEM(5, " 鞋子 ", GOSSIP_SENDER_MAIN, EQUIPMENT_SLOT_FEET);
	player->ADD_GOSSIP_ITEM(5, " 主手武器 ", GOSSIP_SENDER_MAIN, EQUIPMENT_SLOT_MAINHAND);
	player->ADD_GOSSIP_ITEM(5, " 副手 ", GOSSIP_SENDER_MAIN, EQUIPMENT_SLOT_OFFHAND);

	player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
	return true;
}
bool GossipSelect_EnchantNPC(Player* player, Creature* creature, uint32 sender, uint32 action)
{
	if (sender != GOSSIP_SENDER_MAIN)
		return true;

	if (action < 20)
	{
		switch (action)
		{
		case EQUIPMENT_SLOT_CHEST:
			player->ADD_GOSSIP_ITEM(5, " 高级属性 ", GOSSIP_SENDER_MAIN, CHEST_STATS);
			break;
		case EQUIPMENT_SLOT_BACK:
			player->ADD_GOSSIP_ITEM(5, " 敏捷 ", GOSSIP_SENDER_MAIN, CLOAK_AGILITY);
			player->ADD_GOSSIP_ITEM(5, " 护甲 ", GOSSIP_SENDER_MAIN, CLOAK_ARMOR);
			player->ADD_GOSSIP_ITEM(5, " 闪避 ", GOSSIP_SENDER_MAIN, CLOAK_DODGE);
			player->ADD_GOSSIP_ITEM(5, " 狡诈 ", GOSSIP_SENDER_MAIN, CLOAK_SUB);
			break;
		case EQUIPMENT_SLOT_WRISTS:
			player->ADD_GOSSIP_ITEM(5, " 耐力 ", GOSSIP_SENDER_MAIN, BRACER_STAM);
			player->ADD_GOSSIP_ITEM(5, " 力量 ", GOSSIP_SENDER_MAIN, BRACER_STR);
			player->ADD_GOSSIP_ITEM(5, " 治疗效果 ", GOSSIP_SENDER_MAIN, BRACER_HEAL);
			player->ADD_GOSSIP_ITEM(5, " 智力 ", GOSSIP_SENDER_MAIN, BRACER_INT);
			break;
		case EQUIPMENT_SLOT_HANDS:
			player->ADD_GOSSIP_ITEM(5, " 敏捷 ", GOSSIP_SENDER_MAIN, GLOVES_AGI);
			player->ADD_GOSSIP_ITEM(5, " 火焰伤害 ", GOSSIP_SENDER_MAIN, GLOVES_FIRE);
			player->ADD_GOSSIP_ITEM(5, " 冰霜伤害 ", GOSSIP_SENDER_MAIN, GLOVES_FROST);
			player->ADD_GOSSIP_ITEM(5, " 暗影伤害 ", GOSSIP_SENDER_MAIN, GLOVES_SHADOW);
			player->ADD_GOSSIP_ITEM(5, " 治疗效果 ", GOSSIP_SENDER_MAIN, GLOVES_HEALING);
			break;
		case EQUIPMENT_SLOT_FEET:
			player->ADD_GOSSIP_ITEM(5, " 耐力 ", GOSSIP_SENDER_MAIN, BOOTS_STAM);
			player->ADD_GOSSIP_ITEM(5, " 移速 ", GOSSIP_SENDER_MAIN, BOOTS_SPEED);
			player->ADD_GOSSIP_ITEM(5, " 敏捷 ", GOSSIP_SENDER_MAIN, BOOTS_AGI);
			break;
		case EQUIPMENT_SLOT_MAINHAND:
			player->ADD_GOSSIP_ITEM(5, " 十字军 ", GOSSIP_SENDER_MAIN, WEP_CRUSADER);
			player->ADD_GOSSIP_ITEM(5, " 单手敏捷 ", GOSSIP_SENDER_MAIN, WEP1H_AGILITY);
			player->ADD_GOSSIP_ITEM(5, " 双手敏捷 ", GOSSIP_SENDER_MAIN, WEP2H_AGILITY);
			player->ADD_GOSSIP_ITEM(5, " 法术伤害 ", GOSSIP_SENDER_MAIN, WEP_SPELLPOWER);
			player->ADD_GOSSIP_ITEM(5, " 治疗效果 ", GOSSIP_SENDER_MAIN, WEP_HEAL);
			break;
		case EQUIPMENT_SLOT_OFFHAND:
			player->ADD_GOSSIP_ITEM(5, " 精神 ", GOSSIP_SENDER_MAIN, OFFHAND_SPIRIT);
			player->ADD_GOSSIP_ITEM(5, " 耐力 ", GOSSIP_SENDER_MAIN, OFFHAND_STAM);
			player->ADD_GOSSIP_ITEM(5, " 冰霜抗性 ", GOSSIP_SENDER_MAIN, OFFHAND_FROSTRES);
			break;
		}
		player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
	}
	else
	{
		Item* item = nullptr;
		uint32 id = 0;
		switch (action)
		{
		case WEP2H_SUPERIOR_IMPACT:
		case WEP2H_AGILITY:
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND);
			if (item && (action == WEP2H_AGILITY || action == WEP2H_SUPERIOR_IMPACT))
			{
				if (item->GetProto()->SubClass != ITEM_SUBCLASS_WEAPON_AXE2 && item->GetProto()->SubClass != ITEM_SUBCLASS_WEAPON_MACE2
					&& item->GetProto()->SubClass != ITEM_SUBCLASS_WEAPON_SWORD2 && item->GetProto()->SubClass != ITEM_SUBCLASS_WEAPON_POLEARM
					&& item->GetProto()->SubClass != ITEM_SUBCLASS_WEAPON_STAFF)
				{
					player->GetSession()->SendNotification(" 需要装备双手武器. ");
					player->CLOSE_GOSSIP_MENU();
					return true;
				}
			}
			if (action == WEP2H_SUPERIOR_IMPACT)
				id = 1896;
			else if (action == WEP2H_AGILITY)
				id = 2646;
			break;

		case WEP_CRUSADER:
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND);
			id = 1900;
			break;
		case WEP1H_AGILITY:
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND);
			id = 2564;
			break;
		case WEP_SPELLPOWER:
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND);
			id = 2504;
			break;
		case WEP_HEAL:
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND);
			id = 2505;
			break;

		case OFFHAND_SPIRIT:
		case OFFHAND_STAM:
		case OFFHAND_FROSTRES:
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND);
			if (item && item->GetProto()->SubClass != ITEM_SUBCLASS_ARMOR_SHIELD)
			{
				player->GetSession()->SendNotification(" 需要盾牌 ");
				player->CLOSE_GOSSIP_MENU();
				return true;
			}
			if (action == OFFHAND_SPIRIT)
				id = 1890;
			else if (action == OFFHAND_FROSTRES)
				id = 926;
			else if (action == OFFHAND_STAM)
				id = 929;
			break;
		case CHEST_STATS:
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_CHEST);
			id = 1891;
			break;
		case CLOAK_DODGE:
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_BACK);
			id = 2622;
			break;
		case CLOAK_SUB:
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_BACK);
			id = 2621;
			break;
		case CLOAK_ARMOR:
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_BACK);
			id = 1889;
			break;
		case CLOAK_AGILITY:
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_BACK);
			id = 849;
			break;
		case BRACER_STAM:
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WRISTS);
			id = 1886;
			break;
		case BRACER_STR:
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WRISTS);
			id = 1885;
			break;
		case BRACER_HEAL:
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WRISTS);
			id = 2566;
			break;
		case BRACER_INT:
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WRISTS);
			id = 1883;
			break;
		case GLOVES_AGI:
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS);
			id = 2564;
			break;
		case GLOVES_FIRE:
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS);
			id = 2616;
			break;
		case GLOVES_FROST:
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS);
			id = 2615;
			break;
		case GLOVES_SHADOW:
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS);
			id = 2614;
			break;
		case GLOVES_HEALING:
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS);
			id = 2617;
			break;
		case BOOTS_AGI:
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FEET);
			id = 904;
			break;
		case BOOTS_SPEED:
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FEET);
			id = 911;
			break;
		case BOOTS_STAM:
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FEET);
			id = 929;
			break;
		}
		Enchant(player, item, id);
		player->CLOSE_GOSSIP_MENU();
	}
	return true;
}



void LearnSkillRecipesHelper(Player *player, uint32 skill_id)
{
	uint32 classmask = player->getClassMask();

	for (uint32 j = 0; j < sSkillLineAbilityStore.GetNumRows(); ++j)
	{
		SkillLineAbilityEntry const *skillLine = sSkillLineAbilityStore.LookupEntry(j);
		if (!skillLine)
			continue;

		// wrong skill
		if (skillLine->skillId != skill_id)
			continue;

		// not high rank
		if (skillLine->forward_spellid)
			continue;

		// skip racial skills
		if (skillLine->racemask != 0)
			continue;

		// skip wrong class skills
		if (skillLine->classmask && (skillLine->classmask & classmask) == 0)
			continue;

		SpellEntry const* spellEntry = sSpellMgr.GetSpellEntry(skillLine->spellId);
		if (!spellEntry || !SpellMgr::IsSpellValid(spellEntry, player, false))
			continue;

		player->learnSpell(skillLine->spellId, false);
	}
}
bool LearnAllRecipesInProfession(Player *pPlayer, SkillType skill)
{
	ChatHandler handler(pPlayer->GetSession());
	char* skill_name;

	SkillLineEntry const *SkillInfo = sSkillLineStore.LookupEntry(skill);
	skill_name = SkillInfo->name[sWorld.GetDefaultDbcLocale()];

	if (!SkillInfo)
	{
		sLog.outError("Profession NPC: received non-valid skill ID");
		return false;
	}

	pPlayer->SetSkill(SkillInfo->id, 300, 300);
	LearnSkillRecipesHelper(pPlayer, SkillInfo->id);
	pPlayer->GetSession()->SendNotification(" %s 已学会所有图纸. ", skill_name);
	return true;
}

bool GossipHello_ProfessionNPC(Player* player, Creature* creature)
{

	player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, " 炼金 ", GOSSIP_SENDER_MAIN, 1);
	player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, " 锻造 ", GOSSIP_SENDER_MAIN, 2);
	player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, " 制皮 ", GOSSIP_SENDER_MAIN, 3);
	player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, " 裁缝 ", GOSSIP_SENDER_MAIN, 4);
	player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, " 工程 ", GOSSIP_SENDER_MAIN, 5);
	player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, " 附魔 ", GOSSIP_SENDER_MAIN, 6);
	//player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Jewelcrafting",      GOSSIP_SENDER_MAIN, 7);
	//player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Inscription",        GOSSIP_SENDER_MAIN, 8);
	player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, " 草药 ", GOSSIP_SENDER_MAIN, 9);
	player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, " 剥皮 ", GOSSIP_SENDER_MAIN, 10);
	player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, " 采矿 ", GOSSIP_SENDER_MAIN, 11);

	player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, " 急救 ", GOSSIP_SENDER_MAIN, 12);
	player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, " 钓鱼 ", GOSSIP_SENDER_MAIN, 13);
	player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, " 烹饪 ", GOSSIP_SENDER_MAIN, 14);

	player->PlayerTalkClass->SendGossipMenu(1, creature->GetGUID());

	player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
	return true;
}
void CompleteLearnProfession(Player *pPlayer, Creature *pCreature, SkillType skill)
{
	if (pPlayer->GetFreePrimaryProfessionPoints() == 0 && !(skill == SKILL_COOKING || skill == SKILL_FIRST_AID))
	{
		pPlayer->GetSession()->SendNotification(" 你已经学了两个专业. ");
	}
	else
	{
		if (!LearnAllRecipesInProfession(pPlayer, skill))
			pPlayer->GetSession()->SendNotification(" 呃，发生了点意外. ");
	}
}
bool GossipSelect_ProfessionNPC(Player* player, Creature* creature, uint32 sender, uint32 action)
{
	switch (action)
	{
	case 1:
		if (!player->HasSkill(SKILL_ALCHEMY))
			CompleteLearnProfession(player, creature, SKILL_ALCHEMY);
		break;
	case 2:
		if (!player->HasSkill(SKILL_BLACKSMITHING))
			CompleteLearnProfession(player, creature, SKILL_BLACKSMITHING);
		break;
	case 3:
		if (!player->HasSkill(SKILL_LEATHERWORKING))
			CompleteLearnProfession(player, creature, SKILL_LEATHERWORKING);
		break;
	case 4:
		if (!player->HasSkill(SKILL_TAILORING))
			CompleteLearnProfession(player, creature, SKILL_TAILORING);
		break;
	case 5:
		if (!player->HasSkill(SKILL_ENGINEERING))
			CompleteLearnProfession(player, creature, SKILL_ENGINEERING);
		break;
	case 6:
		if (!player->HasSkill(SKILL_ENCHANTING))
			CompleteLearnProfession(player, creature, SKILL_ENCHANTING);
		break;
	case 7:
	case 8:
		break;
	case 9:
		if (!player->HasSkill(SKILL_HERBALISM))
			CompleteLearnProfession(player, creature, SKILL_HERBALISM);
		break;
	case 10:
		if (!player->HasSkill(SKILL_SKINNING))
			CompleteLearnProfession(player, creature, SKILL_SKINNING);
		break;
	case 11:
		if (!player->HasSkill(SKILL_MINING))
			CompleteLearnProfession(player, creature, SKILL_MINING);
		break;
	case 12:
		if (!player->HasSkill(SKILL_FIRST_AID))
			CompleteLearnProfession(player, creature, SKILL_FIRST_AID);
		break;
	case 13:
		if (!player->HasSkill(SKILL_FISHING))
			CompleteLearnProfession(player, creature, SKILL_FISHING);
		break;
	case 14:
		if (!player->HasSkill(SKILL_COOKING))
			CompleteLearnProfession(player, creature, SKILL_COOKING);
		break;
	}

	player->CLOSE_GOSSIP_MENU();
	return true;
}

/*
* Custom training dummy script
*/

struct npc_training_dummyAI : ScriptedAI
{
	explicit npc_training_dummyAI(Creature* pCreature) : ScriptedAI(pCreature)
	{
		npc_training_dummyAI::Reset();
	}

	uint32 m_uiCombatTimer;
	std::unordered_map<Unit*, time_t> attackers;

	void Reset() override
	{
		m_uiCombatTimer = 15000;
		attackers.clear();
	}

	void AttackStart(Unit* /*pWho*/) override {}

	void Aggro(Unit* pWho) override
	{
		SetCombatMovement(false);
	}

	void AddAttackerToList(Unit* pWho)
	{
		auto itr = attackers.find(pWho);
		if (itr != attackers.end())
		{
			itr->second = std::time(nullptr);
		}
		else
		{
			attackers.emplace(pWho, std::time(nullptr));
		}
	}

	void DamageTaken(Unit* pWho, uint32& /*uiDamage*/) override
	{
		if (pWho)
			AddAttackerToList(pWho);
	}

	void SpellHit(Unit* pWho, const SpellEntry* /*pSpell*/) override
	{
		if (pWho)
			AddAttackerToList(pWho);
	}

	void UpdateAI(const uint32 diff) override
	{
		if (m_creature->isInCombat())
		{
			if (m_uiCombatTimer <= diff)
			{
				for (auto itr = attackers.begin(); itr != attackers.end();)
				{
					if (!itr->first || !itr->first->IsInWorld())
					{
						itr = attackers.erase(itr);
						continue;
					}
					if (itr->second + 10 < std::time(nullptr))
					{
						m_creature->_removeAttacker(itr->first);
						m_creature->getThreatManager().modifyThreatPercent(itr->first, -101.0f);
						itr = attackers.erase(itr);
					}
					++itr;
				}

				if (m_creature->getThreatManager().isThreatListEmpty())
					EnterEvadeMode();

				m_uiCombatTimer = 15000;
			}
			else
				m_uiCombatTimer -= diff;
		}
	}
};

CreatureAI* GetAI_npc_training_dummy(Creature* pCreature)
{
	return new npc_training_dummyAI(pCreature);
}

struct npc_summon_debugAI : ScriptedAI
{
	uint32 m_maxSummonCount = 200;
	uint32 m_summonCount = 0;
	Creature *m_summons[200];

	npc_summon_debugAI(Creature *pCreature) : ScriptedAI(pCreature)
	{
		m_summonCount = 0;
		for (uint32 i = 0; i < m_maxSummonCount; ++i)
			m_summons[i] = nullptr;

		Reset();
	}

	void Reset() override
	{
		m_summonCount = 0;
		for (uint32 i = 0; i < m_maxSummonCount; ++i)
		{
			if (m_summons[i])
				((TemporarySummon*)m_summons[i])->UnSummon();

			m_summons[i] = nullptr;
		}
	}


	void JustDied(Unit* /* killer */) override
	{
		Reset();
	}

	void UpdateAI(const uint32 diff) override
	{
		if (!m_creature->getVictim())
			return;

		if (m_summonCount >= m_maxSummonCount)
			return;

		m_summons[m_summonCount++] = m_creature->SummonCreature(12458, m_creature->GetPositionX(), m_creature->GetPositionY(), m_creature->GetPositionZ(), 0);
	}
};

CreatureAI* GetAI_custom_summon_debug(Creature *creature)
{
	return new npc_summon_debugAI(creature);
}

void AddSC_custom_creatures()
{
	Script *newscript;

	newscript = new Script;
	newscript->Name = "custom_teleport_npc";
	newscript->pGossipHello = &GossipHello_TeleportNPC;
	newscript->pGossipSelect = &GossipSelect_TeleportNPC;
	newscript->RegisterSelf(false);

	newscript = new Script;
	newscript->Name = "custom_enchant_npc";
	newscript->pGossipHello = &GossipHello_EnchantNPC;
	newscript->pGossipSelect = &GossipSelect_EnchantNPC;
	newscript->RegisterSelf(false);

	newscript = new Script;
	newscript->Name = "custom_professions_npc";
	newscript->pGossipHello = &GossipHello_ProfessionNPC;
	newscript->pGossipSelect = &GossipSelect_ProfessionNPC;
	newscript->RegisterSelf(false);

	newscript = new Script;
	newscript->Name = "custom_npc_training_dummy";
	newscript->GetAI = &GetAI_npc_training_dummy;
	newscript->RegisterSelf(false);

	newscript = new Script;
	newscript->Name = "custom_npc_summon_debugAI";
	newscript->GetAI = &GetAI_custom_summon_debug;
	newscript->RegisterSelf(false);
}
