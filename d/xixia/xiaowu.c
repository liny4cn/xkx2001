//Cracked by Roath
// RYU 1/5/97
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "Сľ��");
        set("long", @LONG
��������ͨ��Сľ�ݣ�����һ������ס������������򵥣�һ
�����ӣ��������ӣ�ǽ��������Сľ�����������Ǹ�¯�ӣ�������ŵ�
һ����ˮ����ˮ�����������ĴӺ���ð�˳����������������ӡ�
LONG
        );
        set("exits", ([
        ]));


        setup();
        replace_program(ROOM);
}