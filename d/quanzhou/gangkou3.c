//Cracked by Roath
// gangkou1.c �ۿ�·
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�ۿ�·");
	set("long", @LONG
�����ô�黨��ʯ�̳ɵĿ��������ƽ̹��ʵ��·�����������ų��صĻ�
�������������������Ӷ�����ʦ�������������Ǽ�ֵ���ƵĻ��
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"north" : __DIR__"lingmu",
		"south" : __DIR__"gangkou4",
	]));

        set("objects", ([ 
		__DIR__"npc/biaotou" : 1,
        ]));

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

	set("cost", 1);
        setup();
	replace_program(ROOM);
}