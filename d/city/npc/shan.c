// Change by Server
// /d/city/npc/shan.c
// xbc: 96/11/19

inherit NPC;
inherit F_DEALER;

int do_look(string);
string ask_me();
string ask_beauty();
string ask_ugly();
string ask_age();
string ask_exp();
string ask_marriage();
string ask_fat();
string ask_pk();
string ask_balance();
string ask_mudage();
string ask_lit();
int env_cmp(object o1, object o2);

void create()
{
        set_name("С�", ({ "shan", "xiao shan" }) );
        set("long", "����һ��������ɵɵ������С���\n");
	set("title", "��Ů");
        set("gender", "Ů��");
        set("age", 18);
        set("attitude", "friendly");
        set("shen_type", 1);
        set("str", 18);
        set("int", 23);
        set("con", 19);
        set("dex", 20);
        set("max_qi", 300);
        set("max_jing", 300);
        set("neili", 400);
        set("max_neili", 400);
        set("combat_exp", 80000);

        set_skill("literate", 100);
        set_skill("dodge", 30); 
	set_skill("force", 30);
	set_skill("parry", 30);
	set_skill("unarmed", 30);

        set("inquiry", ([
                "name" : "�Ҿ���С橡�" ,
                "here" : "��������ͤ����������� age, balance, beauty, exp, fat, literate, marriage, mudage, pk, ugly, ",
		"����" : "������˵�ˣ��������ǰ�ˮ����Ů�˺�ʯͷ�������˷���һ����ͣ����Ǻ��ࡣ" ,
		"���" : "������˵�ˣ��������ǰ�ˮ����Ů�˺�ʯͷ�������˷���һ����ͣ����Ǻ��ࡣ" ,
		"kiss" : "�����Ĳ����İ������ǻ��������������ߴ��ط��˰ɡ�",
		"sex" : (: ask_me :),
		"make love" : (: ask_me :),
		"love" : "�̣ϣ֣ţ����������˿��̶�������������" ,
		"����" : "���飿���������˿��̶�������������" ,
		"boyfriend" : "�����ѣ�����˵�ˣ���ǧ��Ҫ��˵��ϲ������" ,
		"������" : "�����ѣ�����˵�ˣ���ǧ��Ҫ��˵��ϲ������" ,
		"girlfriend" : "����˵�ˣ��뽻Ů���ѣ�����ȶ�ѧЩ�Ļ���װ����һ����С�" ,
		"Ů����" : "����˵�ˣ��뽻Ů���ѣ�����ȶ�ѧЩ�Ļ���װ����һ����С�" ,
		"wife" : "��֪��˭˵�ģ����Ӿ���һ������ǰ����Ҫ������������ò����˵�Ů�ˡ�" ,
		"����" : "��֪��˭˵�ģ����Ӿ���һ������ǰ����Ҫ������������ò����˵�Ů�ˡ�" ,
		"husband" : "�ұ�����˵�ˣ��ɷ����һ�������ް���" ,
		"�ɷ�" : "�ұ�����˵�ˣ��ɷ����һ�������ް���" ,
		"divorce" : "��飬����������Ŀ�ʼ�ˡ�" ,
		"���" : "��飬����������Ŀ�ʼ�ˡ�" ,
		"��ˮͰ" : "�ޣ���Ͱ�������ˮ�Ǹ����õģ����Լ�ȥ��ɡ�",
	    "beauty" : (: ask_beauty :),
	    "ugly" : (: ask_ugly :),
	    "age" : (: ask_age :),
	    "exp" : (: ask_exp :),
	    "marriage" : (: ask_marriage :),
	    "fat" : (: ask_fat :),
	    "pk" : (: ask_pk :),
	    "pker" : (: ask_pk :),
	    "balance" : (: ask_balance :),
	    "rich" : (: ask_balance :),
	    "mudage" : (: ask_mudage :),
	    "literate" : (: ask_lit :),
        ]) );

        setup();
        carry_object("d/city/obj/pink_cloth")->wear();
        carry_object("d/city/obj/flower_shoe")->wear();

        set("vendor_goods", ({
                "d/city/obj/rose",
        }) );
}

void init()
{
        object ob;

        ::init();
      	add_action("do_look","kiss1");
       	add_action("do_look","kick");
      	add_action("do_look","slap");
	add_action("do_look","flirt");
	add_action("do_look","loveshoe");
        add_action("do_list", "list");
        add_action("do_buy", "buy");

        if( interactive(ob = this_player()) && !is_fighting()) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }

}

int ask_me()
{
        object me;
 
        me = this_player();
        switch( random(5) ) {
                case 0:
	                message("vision",
   "С���" + me->name() +"ŭ���������Ĳ�����ѽ����å�����ȥ��\n", me );
                        command("slap " + me->query("id"));
                        remove_call_out("kicking");
                        call_out("kicking", 1, me);
                        break;
                case 1:
		        message("vision",
   "С���" + me->name() +"ŭ���������Ĳ�����ѽ����å�����ȥ��\n", me );
                        command("kick " + me->query("id"));
                        remove_call_out("kicking");
                        call_out("kicking", 1, me);
                        break;
                case 2:
                        command("faint " + me->query("id"));
                        break;
                case 3:
                        command("rascal " + me->query("id"));
			command("slap " + me->query("id"));
                        break;
                case 4:
			command("xixi " + me->query("id"));
                        command("benger " + me->query("id"));
                        break;
        }
   	return 1;
}

int do_look(string target)
{
        object me;
 
        me = this_player();
        if (target=="shan" || target=="xiao shan") 
        if ((string)me->query("gender") != "Ů��") {
                   message("vision",
   "С���" + me->name() +"���������Ĳ�����ѽ��\n", me );

	switch( random(5) ) {
		case 0:
                        command("slap " + me->query("id"));
			remove_call_out("kicking");
			call_out("kicking", 1, me);
                        break;
                case 1:
                        command("kick " + me->query("id"));
                        remove_call_out("kicking");
                        call_out("kicking", 1, me);
                        break;
                case 2:
                        command("faint " + me->query("id"));
                        break;
                case 3:
                        command("stare " + me->query("id"));
                        break;
                case 4:
                        command("rascal " + me->query("id"));
			command("slap " + me->query("id"));
                        break;
        }
	}
        return 1;

}

/*
void greeting(object ob)
{
	object zhn;

        if( !ob || environment(ob) != environment() ) return;

        switch( random(2) ) {
                case 0:
                say( "С橹�������һ�Զ��飬���������ˣ�̧��ͷ������һ�ۣ�ָ��ָǽ�ϵ�
���ܵ����ӵ������Լ����ɣ������Եľ��Ҹ���λ���ɡ�˵������ͷ����ȥ�ˡ�\n");
          	break;

                case 1:
                say( "С橹�������һ�Զ��飬���������ˣ������������˵����λ" + RANK_D->query_respect(ob) + "��
���������ȱ�ˮ���������ɣ������Ͽ������в�����ʾ�š�\n");
		break;
        }
        zhn = new("/u/xbc/obj/zhinan");
        zhn->move(ob);
        message_vision("С橸���$Nһ��С���ӡ�\n", ob);

	return;
}

*/

void kicking(object me)
{
        if (!me || environment(me) != environment()
	|| environment(this_object())->query("short") != "����ͤ")
                return;

        me->move("/d/city/dongdajie3");
         message("vision","ֻ�����ء���һ����������" +  me->query("name") +
                "������ͤ����˳���������һ������ӡ��ƨ������һ��СЬӡ��\n", environment(me), me);
}

int env_cmp(object o1, object o2)
{
        string env1, env2;
        object where;
        env1 = (where = environment(o1)) ? base_name(where) : "none";
        env2 = (where = environment(o2)) ? base_name(where) : "none";
        return strcmp(env1, env2);
}

string ask_beauty()
{
	object where, ob, obj1, obj2,*ob_list;
	string msg, name1, name2;
	int i, per = 0;

	ob_list = users();
        for( i = 0; i < sizeof(ob_list); i++) {
                where = environment(ob_list[i]);
                if( ob_list[i]->query("per") > per 
                && ob_list[i]->query("gender") == "Ů��"
		&& !wizardp(ob_list[i])
                && where
                && strsrch(file_name(where), "/d/") >= 0) {
                        obj1 = ob_list[i];
                        per = obj1->query("per");
                }
        }

	per = 0;
	for( i = 0; i < sizeof(ob_list); i++) {
		where = environment(ob_list[i]);
		if( ob_list[i]->query("per") > per 
		&& ob_list[i]->query("gender") != "Ů��"
		&& !wizardp(ob_list[i])
		&& where
		&& strsrch(file_name(where), "/d/") >= 0) {
			obj2 = ob_list[i];
			per = obj2->query("per");
		}
	}

	if ( !obj1 && !obj2 ) {
		msg ="�ף����أ�\n";
		return msg;
	}

	obj1->set_temp("top_girl",1);
	obj2->set_temp("top_boy",1);
	name1 = obj1->query("name")+"("+obj1->query("id")+")";
	name2 = obj2->query("name")+"("+obj2->query("id")+")";
	msg ="��������������������"+name1+"��Ư����"+name2+"��Ӣ����\n";

	return msg;
}

string ask_ugly()
{
	object where, ob, obj,*ob_list;
	string msg, name;
	int i, per = 30;

	ob_list = users();

	per = 30;
	for( i = 0; i < sizeof(ob_list); i++) {
		where = environment(ob_list[i]);
		if( ob_list[i]->query("gender") != "Ů��"
		&& !wizardp(ob_list[i])
		&& ob_list[i]->query("per") < per 
		&& where
		&& strsrch(file_name(where), "/d/") >= 0) {
			obj = ob_list[i];
			per = obj->query("per");
		}
	}

	if ( !obj ) {
	msg ="��Ҷ���Ӣ���Ľ��ء�\n";
	return msg;
	}

	obj->set_temp("ugly_boy",1);
	name = obj->query("name")+"("+obj->query("id")+")";
	msg ="�ţ���������������"+name+"�������\n";

	return msg;
}

string ask_age()
{
	object where,ob,obj,*ob_list;
	string msg, name;
	int i, age = 0;

	ob_list = users();

	for( i = 0; i < sizeof(ob_list); i++) {
		where = environment(ob_list[i]);
		if( ob_list[i]->query("combat_exp") > 1000 
		&& !wizardp(ob_list[i])
		&& ob_list[i]->query("mud_age") > age 
		&& where
		&& strsrch(file_name(where), "/d/") >= 0) {
			obj = ob_list[i];
			age = obj->query("mud_age");
		}
	}

	if ( !obj ) {
		msg ="�ף�զû�����أ�\n";
		return msg;
	}

	obj->set_temp("oldest",1);
	name = obj->query("name")+"("+obj->query("id")+")";
	msg ="���������˴��׺������⣬��������������"+name+"������\n";

	return msg;
}

string ask_exp()
{
	object where,ob,obj,*ob_list;
	string msg, name;
	int i, exp = 0;

	ob_list = users();

	for( i = 0; i < sizeof(ob_list); i++) {
		where = environment(ob_list[i]);
		if( ob_list[i]->query("combat_exp") > exp 
		&& !wizardp(ob_list[i])
		&& where
		&& strsrch(file_name(where), "/d/") >= 0) {
			obj = ob_list[i];
			exp = obj->query("combat_exp");
		}
	}

	if ( !obj ) {
		msg ="�ף�������ôһ�����ֶ�û���ˣ�\n";
		return msg;
	}

	obj->set_temp("highhand",1);
	name = obj->query("name")+"("+obj->query("id")+")";
	msg ="������������������"+name+"���书��ߣ�\n";

	return msg;
}


string ask_marriage()
{
	object where,ob,obj,*ob_list;
	string msg, name;
	int i, married_times = 0;

	ob_list = users();
	for( i = 0; i < sizeof(ob_list); i++) {
		where = environment(ob_list[i]);
		if( ob_list[i]->query("married_times") > married_times 
		&& !wizardp(ob_list[i])
		&& where
		&& strsrch(file_name(where), "/d/") >= 0) {
			obj = ob_list[i];
			married_times = obj->query("married_times");
		}
	}

	if ( !obj ) {
		msg ="�ף�������ô��û�˽���飿\n";
		return msg;
	}

	obj->set_temp("most_married",1);
	name = obj->query("name")+"("+obj->query("id")+")";
	msg ="��������������������"+name+"���Ĵ�����ࡣ\n";

	return msg;
}

string ask_fat()
{
	object where,ob,obj,*ob_list;
	string msg, name;
	int i, fat = 0;

	ob_list = users();
	for( i = 0; i < sizeof(ob_list); i++) {
		where = environment(ob_list[i]);
		if( ob_list[i]->max_food_capacity() > fat 
		&& !wizardp(ob_list[i])
		&& where
		&& strsrch(file_name(where), "/d/") >= 0) {
			obj = ob_list[i];
			fat = obj->max_food_capacity();
		}
	}

	if ( !obj ) {
		msg ="�ף����ڵ�����ô����ô�ݣ�\n";
		return msg;
	}

	obj->set_temp("fat",1);
	name = obj->query("name")+"("+obj->query("id")+")";
	msg ="��������������������"+name+"���ܳԡ�\n";

	return msg;
}

string ask_pk()
{
	object where,ob,obj,*ob_list;
	string msg, name;
	int i, pk = 0;

	ob_list = users();
	for( i = 0; i < sizeof(ob_list); i++) {
		where = environment(ob_list[i]);
		if( ob_list[i]->query("PKS") > pk 
		&& !wizardp(ob_list[i])
		&& where
		&& strsrch(file_name(where), "/d/") >= 0) {
			obj = ob_list[i];
			pk = obj->query("PKS");
		}
	}

	if ( !obj ) {
		msg ="��������û��ɱ���ˡ�\n";
		return msg;
	}

	obj->set_temp("pk_most",1);
	name = obj->query("name")+"("+obj->query("id")+")";
	msg ="��������������������"+name+"ɱ������࣡\n";

	return msg;
}

string ask_balance()
{
	object where,ob,obj,*ob_list;
	string msg, name;
	int i, balance = 0;

	ob_list = users();
	for( i = 0; i < sizeof(ob_list); i++) {
		where = environment(ob_list[i]);
		if( ob_list[i]->query("balance") > balance 
		&& !wizardp(ob_list[i])
		&& where
		&& strsrch(file_name(where), "/d/") >= 0) {
			obj = ob_list[i];
			balance = obj->query("balance");
		}
	}

	if ( !obj ) {
		msg ="��������û��ɱ���ˡ�\n";
		return msg;
	}

	obj->set_temp("richest",1);
	name = obj->query("name")+"("+obj->query("id")+")";
	msg ="��������������"+name+"����Ǯ��\n";

	return msg;
}

string ask_mudage()
{
	object me = this_player();
        int t, mm, d, h, m, s;
        string time, msg;

        t = me->query("mud_age");
        s = t % 60;             t /= 60;
        m = t % 60;             t /= 60;
        h = t % 24;             t /= 24;
        d = t % 30;             t /= 30;
        mm = t;

        if(mm) time = chinese_number(mm) + "��";
        else time = "";

        if(d) time += chinese_number(d) + "��";
        if(h) time += chinese_number(h) + "Сʱ";
        if(m) time += chinese_number(m) + "��";
        time += chinese_number(s) + "��";

        msg ="���Ѿ�����������̶������" + time + "��\n";
        return msg;

}

string ask_lit()
{
        object where,ob,obj,*ob_list;
        string msg, name;
        int i, lit_level = 0;

        ob_list = users();
        for( i = 0; i < sizeof(ob_list); i++) {
                where = environment(ob_list[i]);
                if( ob_list[i]->query_skill("literate", 1) > lit_level 
                && !wizardp(ob_list[i])
                && where
                && strsrch(file_name(where), "/d/") >= 0) {
                        obj = ob_list[i];
                        lit_level = obj->query_skill("literate", 1);
                }
        }

        obj->set_temp("highest_lit",1);
        name = obj->query("name")+"("+obj->query("id")+")";
        msg ="��������������"+name+"��������ࡣ\n";

        return msg;
}
