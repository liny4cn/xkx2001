//Cracked by Roath
// Jay 8/9/96

inherit ROOM;

void create()
{
        set("short", "�ּ��");
        set("long", @LONG
������һ���ּ�С���������������ѡ������ǹ����ˡ�����ɽ��ï
�ܣ�������棬��λ��·Ҫʮ��С�ġ�
LONG
        );
        set("exits", ([
		"northeast" : __DIR__"dlroad4",
		"west" : __DIR__"dlroad6",
	]));

	set("objects", ([
            "/d/wudang/npc/bee" : 1,
	]));
	set("cost",1);
	set("outdoors", "wudang");
	setup();
        replace_program(ROOM);
}