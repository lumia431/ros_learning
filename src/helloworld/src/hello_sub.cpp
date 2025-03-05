/*
    ����: �����˵���Ϣ

*/

#include "ros/ros.h"
#include "helloworld/Person.h"

void doPerson(const helloworld::Person::ConstPtr& person_p){
    ROS_INFO("���ĵ�����Ϣ:%s, %d, %.2f", person_p->name.c_str(), person_p->age, person_p->height);
}

int main(int argc, char *argv[])
{   
    setlocale(LC_ALL,"");

    //1.��ʼ�� ROS �ڵ�
    ros::init(argc,argv,"listener_person");
    //2.���� ROS ���
    ros::NodeHandle nh;
    //3.�������Ķ���
    ros::Subscriber sub = nh.subscribe<helloworld::Person>("chatter_person",10,doPerson);

    //4.�ص������д��� person

    //5.ros::spin();
    ros::spin();    
    return 0;
}