//Cracked by Roath
// xiongdan.c �ܵ�
// Modified by xQin 9/00 to fix the unlimited consumption bug

#include <ansi.h>

inherit ITEM;

int cure_ob(string);

void init();

void create()
{
	set_name("�ܵ�", ({ "xiong dan", "dan" }) );
        set_weight(1000);
        if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
        	set("long", "����һ�ű�ȭͷ������ܵ������巢���ںڵ����⡣\n");
		set("value", 10000);
		set("medicine", 1);
	}
	setup();
}

int cure_ob(object me)
{
        me->add("food", 50);

        if ( (int)me->query_condition("bonze_drug" ) > 0 ){
                me->add("max_jingli", -1);
                me->add("eff_jingli", -1);
                me->set("jingli", 0);
                me->apply_condition("bonze_drug", 30);
                message_vision(HIR "$N����һ���ܵ���ֻ���øγ���ϣ��������ѣ�ԭ����ʳ̫��ҩ�ҩЧ�ʵ��䷴��\n" NOR, this_player());
		destruct(this_object());
                return 1;
        }

        if( !me->query_temp("cbs/xiongdan") ) {
                me->add_temp("apply/damage", 30);
                me->set_temp("cbs/xiongdan", 1);
                me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), me->query("con"));
        }

        me->add("neili", 200);
        me->apply_condition("bonze_drug", 
        me->query_condition("bonze_drug")+30);
        message_vision(HIY "$N����һ���ܵ���ֻ���õ���������������о���\n" NOR, me);

        destruct(this_object());
        return 1;
}

void remove_effect(object me)
{
        me->add_temp("apply/damage", -30);
        me->delete_temp("cbs/xiongdan");
        if( wizardp(me) )
                tell_object(me, "����һ������ܵ����������ȶ�û�ˡ�\n");
}


