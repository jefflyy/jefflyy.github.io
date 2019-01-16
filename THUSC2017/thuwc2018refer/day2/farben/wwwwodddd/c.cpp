#include <bits/stdc++.h>
using namespace std;

const int d[9][999] = {{}, {}, {2}, {3, 9, 21, 45, 93, 219}, {4, 16, 64, 232, 784, 2656, 9496, 34840, 127504, 468616, 1725640, 6360016, 23451952, 86494984, 319047424, 176921489, 341631812}, {5, 25, 125, 625, 3005, 13825, 63845, 305185, 1470365, 7113505, 34401845, 166503745, 806139365, 903547204, 903216119, 542977028, 323080384, 933588563, 245001466, 217963321, 20482429, 724242719, 945621102, 251636219, 797004759, 919825210, 822599660, 349963818, 500077473, 334257929, 415474473, 765534864, 75450659, 751510611, 940855832, 454939307, 857438052, 269311339, 868193738, 636253284, 543107901, 444295312, 393049096, 550023504, 269687722}, {6, 36, 216, 1296, 7776, 45936, 264816, 1529856, 9008496, 53258976, 315221616, 866880649, 55884899, 483506201, 876846267, 552401777, 463889233, 455943071, 293587581, 319885589, 238945474, 722988084, 926302994, 76526212, 838282896, 222174451, 851794981, 287634868, 296988385, 956264019, 12167659, 256340194, 473429329, 543641180, 873062713, 32786593, 707495558, 807536573, 561579222, 404406847, 879459863, 843577830, 280044553, 475315352, 650035834, 550711406, 779857452, 314565255, 301585581, 934490973, 833297068, 244107807, 61308453, 429600225, 623235754, 475837300, 682069321, 757633788, 241060300, 556711079, 851849284, 873655308, 513049896, 528195130, 590560762, 216246798, 922688268, 960420558, 558615981, 573385682, 667992786, 562208852, 15241170, 878927836, 147872407, 366069032, 758587486, 356186164, 992281671, 786640941, 822160174, 104690831, 300812911, 799991003, 665843811, 830321018, 368412359, 162583625, 889484458, 329014549, 133127099, 79006269, 787648593, 44202476, 789970658, 158420892, 371483335, 394842506, 567847649, 782189325, 14619420, 900032482, 349194688, 353628784, 349910365, 122462951, 776570303, 685657759, 595552668, 516951572, 893580695, 225882152, 48899614, 601076710, 545779687, 245608708, 585457303, 896379716, 308121822, 482111785, 102191533, 654760125, 114694544, 656398661, 846955008, 701123312, 96855058, 695085508, 861748887, 225965815, 346218943}, {7, 49, 343, 2401, 16807, 117649, 818503, 5623681, 38675287, 268615249, 869163296, 13073990, 611079937, 993727399, 53913585, 640590288, 868994356, 401217177, 254756223, 480098846, 543138002, 966380710, 742573033, 362519843, 14675419, 487759357, 999300341, 833915923, 314279646, 6871396, 844009879, 765135375, 5875334, 11775247, 13254195, 443841515, 654552976, 938100748, 495998091, 615333989, 284801544, 173555787, 540951599, 234678025, 155357689, 595288264, 761964999, 286627266, 119533964, 837722689, 186644491, 768348482, 702399639, 902708395, 311583988, 472053092, 488118378, 233803480, 793498577, 21584398, 617854772, 261594300, 44867240, 598998392, 477383380, 987976117, 717981890, 187315096, 943432647, 310371315, 804518701, 728298955, 450927185, 318998737, 565214210, 878481742, 949128795, 540309348, 858480488, 352338762, 317208298, 563049179, 735103787, 104102872, 976638927, 797667282, 11229945, 987239774, 872927299, 124183924, 360870141, 865114405, 56253386, 177277900, 88874714, 448942389, 432839679, 953200468, 511073178, 353208082, 271882848, 969672163, 25363253, 70937824, 486688581, 404477043, 767350676, 170673185, 226452599, 736382777, 45513369, 488703036, 13587194, 265188940, 323551564, 392544388, 329179264, 6885974, 598505332, 481798793, 295835537, 69062220, 899895359, 198163752, 518782060, 935011494, 404818589, 112566998, 556695188, 634378478, 732676352, 133564137, 25798960, 193298356, 855713307, 204322908, 381244187, 99958364, 645214603, 854968698, 761606044, 174031106, 580375576, 375096267, 4042802, 398792982, 182009096, 712526812, 701765145, 529181804, 898317429, 218906966, 719999194, 931622922, 668224987, 780444040, 230502621, 228609449, 870103393, 674777650, 793626437, 648050578, 907175631, 931406075, 240459924, 218092788, 547053156, 634626038, 717023446, 661807111, 829708357, 658291434, 586332674, 512966939, 762728931, 694141692, 967028920, 427782731, 633092410, 376050359, 183920564, 781817233, 413836967, 307910709, 903776010, 735892798, 360738914, 678174213, 679236172, 230878321, 403079653, 18665482, 125768823, 239596958, 864116374, 97967758, 164383767, 629900360, 638196789, 923141603, 136701840, 214754547, 358587833, 829751999, 328923797, 353441076, 380213483, 26282303, 297254335, 5868613, 2804722, 387059151, 789502274, 185565536, 216434038, 273338784, 37460503, 511760986, 93984652, 908874622, 421282496, 444170090, 884470432, 755614212, 142516228, 504636462, 396195545, 286125142, 7933538, 203866982, 222528724, 584452396, 838102232, 919259323, 827747738, 798228747, 984871279, 83323932, 614553409, 317188959, 599453658, 366214896, 405655596, 544339391, 762380748, 264990881, 553190122, 745310410, 832579306, 867339092, 915374156, 834066649, 955025438, 429394766, 387272357, 167262517, 759376675, 597491451, 904484914, 363960933, 633469979, 869045398, 218247070, 677542228, 266463992, 628781904, 352670081, 920327926, 739102297, 722297776, 769735973, 871216671, 179144317, 369182406, 133076429, 758782403, 614749959, 23126417, 611193412, 263102922, 357226773, 643396416, 664733439, 387347124, 952287997, 953921137, 31902287, 440032754, 519994385, 699983461, 604314455, 477818433, 133088502, 776998234, 37046088, 716909887, 919953839, 746467362, 470875753, 704813293, 236350668, 137391472, 781319293, 557397018, 258605993, 825603130, 633770264, 120219964, 161242140, 770294083, 968912055, 769043077, 914989461, 742475560, 791199780, 597705298, 143948906, 711016349, 813204420, 334480714, 70916094, 593569258, 151201476, 734489825, 53821683, 934472370, 750372726, 109007291, 91897246, 629348234, 95787596, 267174621, 745263041, 833585806, 629335411, 342403342, 514257657, 749404347, 403376794, 879173901, 477788834, 267084133, 692055821, 525193066, 432645307, 984143871, 244269129, 993654927, 641511135, 815706911, 67968059, 565386750, 494889725, 247428568, 327446664, 293181787, 267657704, 208008750, 276832000, 230134734, 714521077, 83640043, 566428115, 29535296, 145354444, 666381926, 992112333, 303250442, 300769344, 558219753, 628526301, 195453048, 873328727, 999488508, 119127320, 823973672, 385145810, 95322745, 595040901, 760705507, 791213328, 760567385, 494253974, 742897137, 412440299, 962990851, 832096729, 825444941, 288642346, 665228848, 692776352, 73363926, 184777238, 909283670, 930479128, 275322065, 247158237, 792801839, 2410000, 701281960, 778213070, 826204767, 526184552, 257228538, 782169419, 718587159, 914504970, 639124015, 163863493}};
const int a[9][999] = {{}, {}, {0, 1}, {0, 2, 2, 1000000006, 1000000005, 1000000004, 1000000006}, {0, 4, 1000000006, 1, 1000000005, 999999999, 999999990, 999999993, 2, 999999998, 18, 23, 5, 7, 0, 0, 1000000003, 1000000003}, {0, 5, 1000000006, 2, 1, 1000000001, 999999950, 999999888, 999999861, 999999766, 999999929, 999999707, 370, 837, 1213, 610, 1171, 1830, 999999162, 115, 999999163, 999998834, 999994353, 999999285, 999997782, 999997737, 999998268, 2503, 373, 999998305, 3762, 2619, 1105, 999998539, 2919, 999999711, 999999835, 68, 1392, 999999883, 16, 456, 400, 240, 192, 288}, {0, 6, 1000000005, 12, 999999994, 5, 999999957, 999999559, 999999080, 999998217, 999997548, 999996344, 47, 999998073, 33128, 52072, 136222, 152972, 91065, 65733, 999955386, 999588063, 998830398, 998260811, 998297012, 999163243, 994165080, 991974669, 996116576, 2807363, 13558353, 997037534, 39235886, 85654940, 110827506, 41365815, 978978435, 93218224, 164892618, 13927038, 562912533, 771321300, 965011201, 835321352, 634194048, 889066230, 953163650, 878190764, 460010303, 684312041, 548204853, 608010979, 179982084, 227826961, 818370526, 451348385, 803007399, 693455486, 378294261, 924698432, 944761643, 270309071, 873113915, 793746856, 200243807, 322095256, 87677704, 319668500, 783560924, 790772175, 369187864, 140859227, 349859658, 631426585, 782039070, 67885082, 835132718, 49616680, 282792562, 330323164, 732637271, 230975002, 116109196, 886247018, 765631897, 269216721, 862063652, 639379219, 936011210, 173868589, 241480135, 398874422, 874757826, 960020433, 203549148, 842620787, 195018181, 963469382, 913064622, 716014212, 741473025, 75821683, 159335840, 482498289, 559939158, 314363448, 51538938, 778364348, 8365497, 879573490, 920947292, 124076643, 144490645, 422055922, 736757760, 347764750, 695285774, 80640505, 268186105, 474888192, 616132608, 326682624, 297750528, 990415367, 72695808, 845613575, 857115143, 862423559, 891177479, 946915847, 31850496, 63700992}, {0, 8, 999999998, 13, 0, 999999999, 999999982, 999999857, 999996451, 999996527, 999989816, 999978096, 999961987, 999924280, 38049, 999880715, 1419892, 1951388, 5311062, 10505810, 16094505, 3079773, 38047274, 10512993, 850038574, 731469180, 290700101, 387128425, 148700701, 880065743, 589043100, 294428323, 559638260, 598110350, 811717323, 97319849, 830367378, 584618896, 776691623, 825929297, 760332569, 823286591, 699894962, 73156678, 208357268, 157936399, 839472733, 327841005, 805906380, 378539109, 354236555, 726318008, 381078211, 289670519, 937027131, 91131249, 301195738, 758453409, 484029063, 662080976, 915059724, 228533778, 272443796, 385406676, 367676058, 865362626, 286356863, 307716634, 705946384, 869856470, 782551769, 703904776, 913061726, 581684523, 410565815, 429055668, 995576042, 625436033, 487258472, 79577377, 691334271, 34431409, 757114241, 365702616, 289855132, 706750782, 677303697, 288449471, 22984491, 902833463, 32438350, 956868697, 106596712, 826432864, 556738470, 802459922, 765703064, 538174742, 804366026, 413751749, 201243657, 930602656, 161180839, 364387208, 765534699, 619102160, 811114084, 712595943, 373541212, 444090519, 338490847, 565516756, 988037207, 587536727, 376379924, 46912871, 171418271, 160880676, 726875897, 536814802, 196688776, 317779448, 378179965, 920764146, 903221839, 33745006, 692994758, 309230513, 111378117, 982551754, 508615263, 641061467, 732010973, 633819182, 161090109, 431557050, 367896031, 607736670, 76792724, 78024709, 260044925, 37660394, 37699272, 33669982, 877200582, 552270444, 45539160, 999206870, 483462022, 472989092, 919008393, 301714757, 867933108, 655807437, 673998892, 785908706, 490103184, 653321286, 932970656, 833009347, 328557471, 890304325, 146069701, 243806019, 661234519, 709306174, 596691901, 596574086, 76111221, 674491946, 129147985, 985039291, 56065093, 712732443, 452891372, 993735467, 133311806, 627679151, 369274626, 403945286, 819656439, 621218006, 825237485, 371207586, 231351522, 3863786, 601943536, 344856557, 532015273, 152091464, 28304052, 293554246, 57610737, 669644045, 674033113, 746169936, 68143830, 772903222, 461732246, 763727998, 984383407, 341128470, 785459526, 590057248, 729449070, 400745651, 376358569, 132475947, 294976698, 669397431, 143696612, 478385559, 243303394, 602119463, 905737892, 940257576, 702100421, 98759576, 116429731, 354024377, 916258769, 264684993, 355325701, 199663848, 466482870, 278800066, 726955610, 686110432, 454862177, 786057224, 438797939, 73664170, 889393111, 894637913, 439677044, 140024915, 922335713, 630701015, 804179342, 316758236, 422074851, 722400342, 301280228, 710748509, 236538824, 547905368, 693075423, 88595360, 941816587, 422014019, 624811701, 559836534, 188611318, 409680261, 977881539, 476278374, 571923105, 834856828, 333802642, 827857673, 781562421, 614327597, 574525723, 965705418, 351249753, 406957462, 570105321, 940854982, 666773398, 522225060, 454154589, 14597802, 962633549, 757248633, 84847848, 966028207, 591657306, 359099247, 159502682, 165475065, 327917413, 109367543, 308856648, 349986766, 535443247, 525926041, 358398468, 315756710, 190547322, 795198087, 900278703, 586278917, 915109848, 7052980, 639415393, 825087888, 484935494, 770450911, 365046295, 560386965, 488931568, 56635929, 272273784, 948842454, 954205329, 812157505, 15991594, 841340231, 7286480, 273752414, 483193902, 158892250, 7862606, 713316559, 224827001, 26879504, 924612572, 59295983, 603643063, 359533039, 13688383, 24679348, 520115182, 957634819, 583447150, 335423094, 683506755, 506622618, 169719634, 902851094, 67624519, 286852344, 336283122, 607248096, 444042031, 455562376, 439032384, 784730598, 35295189, 190031504, 57266574, 879952393, 621138726, 507972141, 857972482, 984923513, 384274933, 824873982, 279746426, 383000508, 106351052, 948070279, 942680150, 233788862, 703859, 977365116, 262630972, 98643161, 734938302, 241040988, 872065807, 943501556, 132390074, 506715988, 160170953, 24894995, 331653026, 70316093, 457520627, 565287670, 468596777, 235574131, 369945261, 933631851, 825156568, 671751466, 876752121, 809740298, 224798781, 136992441, 541402150, 709447269, 967349664, 97238580, 1336196, 350083444, 203699288, 348721381, 654231007, 390002436, 88082424, 307411696, 467583589, 552773501, 915050490, 12768499, 183571639, 606204253, 823991371, 182211557, 598956578, 247309301, 890803007, 629395507, 652457145, 651744399, 324285685, 597420699, 103571403, 827381002}};
const int m[9] = {0, 0, 1, 6, 17, 45, 131, 409};
int b[999];
int c[999];
int p = 1000000007;
long long pp = (long long)p * p;
int k;
void mul(int c[], const int b[]) {
	long long w[999] = {};
	for (int i = 0; i < m[k]; i++) {
		for (int j = 0; j < m[k]; j++) {
			w[i + j] += (long long)c[i] * b[j];
			if (w[i + j] >= pp) {
				w[i + j] -= pp;
			}
		}
	}

	for (int i = 2 * m[k] - 2; i >= m[k]; i--) {
		w[i] %= p;
		for (int j = 1; j <= m[k]; j++) {
			w[i - j] += w[i] * a[k][j];
			if (w[i - j] >= pp) {
				w[i - j] -= pp;
			}
		}
	}

	for (int i = 0; i < m[k]; i++) {
		c[i] = w[i] % p;
	}
}

int solve(int n) {
	n--;
	memset(c, 0, sizeof c);
	memset(b, 0, sizeof b);
	c[0] = 1;
	b[1] = 1;
	for (; n > 0; mul(b, b)) {
		if (n & 1) {
			mul(c, b);
		}
		if (!(n >>= 1)) {
			break;
		}
	}
	int ans = 0;
	for (int i = 0; i < m[k]; i++) {
		ans = (ans + (long long)c[i] * d[k][i]) % p;
	}
	return ans;
}

int phi(int x) {
	int re = x;
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			re = re / i * (i - 1);
			while (x % i == 0) {
				x /= i;
			}
		}
	}
	if (x > 1) {
		re = re / x * (x - 1);
	}
	return re;
}

int pw(int x, int y) {
	int re = 1;
	for (; y > 0; y >>= 1) {
		if (y & 1) {
			re = (long long)re * x % p;
		}
		x = (long long)x * x % p;
	}
	return re;
}
int main() {
	int n;
	scanf("%d%d", &n, &k);
	long long ans = 0;
	vector<int> divisors;
	for (int i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			divisors.push_back(i);
			if (i * i < n) {
				divisors.push_back(n / i);
			}
		}
	}
	for (int i = 0; i < divisors.size(); i++) {
		ans = (ans + (long long)solve(divisors[i]) * phi(n / divisors[i])) % p;
	}
	ans = ans * pw(n, p - 2) % p;
	printf("%lld\n", ans);
	return 0;
}