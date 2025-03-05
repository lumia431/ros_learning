/*
    ����: ѭ�������˵���Ϣ

*/

#include "ros/ros.h"
#include "helloworld/Person.h"

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");

    //1.��ʼ�� ROS �ڵ�
    ros::init(argc,argv,"talker_person");

    //2.���� ROS ���
    ros::NodeHandle nh;

    //3.���������߶���
    ros::Publisher pub = nh.advertise<helloworld::Person>("chatter_person",1000);

    //4.��֯����������Ϣ����д�����߼���������Ϣ
    helloworld::Person p;
    p.name = "sunwukong";
    p.age = 2000;
    p.height = 1.45;

    ros::Rate r(1);
    while (ros::ok())
    {
        pub.publish(p);
        p.age += 1;
        ROS_INFO("�ҽ�:%s,����%d��,��%.2f��", p.name.c_str(), p.age, p.height);

        r.sleep();
        ros::spinOnce();
    }



    return 0;
}