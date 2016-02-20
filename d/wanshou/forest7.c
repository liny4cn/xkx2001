//Cracked by Roath
// /d/wanshou/forest7.c
// snowbird July 1999
// 1.1.1.1

#include "room.h"

inherit ROOM;

void reset_path(object me);
void check_out(object me);

void create()
{
        set("short", "����");
        set("long", @LONG
��һƬ������ľï�ܣ�������գ������������ޱ��޼ʡ��ڰ�
�оͻ���ʲô����ͻ�������������ȥ�Ƶġ����������һƬ����
�ޱߡ������ڰ������ֲ���һ�󵨺����������ǸϿ��˳�ȥ�ĺá�
LONG
        );
        set("exits", ([
				"north" : __DIR__"forest1",
				"south" : __DIR__"forest4",
				"east" : __DIR__"forest8",
				"west" : __DIR__"forest9",
        ]));

        set("outdoors", "wanshou-shanzhuang");

	    set("cost", 1);
        setup();

}

void  init()
{              
	object  me=this_player();

	if(  me->query_temp("tree7")  ==  0  )
	{
		me->set_temp("tree7",  1);
	}
	else  if(  me->query_temp("tree7")  ==  1  )
	{
		reset_path(me);
	}
	
	if(  check_out(me)  ) 
	{ 
        set("exits/north", __DIR__"shijie");
        call_out("close_exit_shijie", 5);
	}
}

void close_exit_shijie()
{
       set("exits/north", __DIR__"forest1");
}

void  reset_path(object me)
{
	int i;

	for (i=1; i<10; i++) {
   	   if(  me->query_temp("tree"+i)  )     	   
   	        me->delete_temp("tree"+i);
	}
	return;
}

int check_out(object  me)
{
	int i;

	for (i=1; i<10; i++) {
   	   if(  me->query_temp("tree"+i) != 1 )     	   
		  return 0;
	}
	reset_path(me); 
	return 1;
}