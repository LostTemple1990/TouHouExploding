﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.Serialization;

namespace NetWork
{
    public sealed class Ack : Community//通知，无须回复。所有通知都需要继承于此类
    {
        public string AckID//该指令回复的ID
        {
            get
            {
                return ackID;
            }
        }
        [DataMember]
        private string ackID;
        public Ack(string toAckID)//从ID创建回复对象
        {

            netAttribute = Community.NetAttributes.Respond;
            ackID = toAckID;
        }
        public static Ack GetRespond(Enquire toRespond)//从对象创建回复
        {
             return new Ack(toRespond.CommunityID);
        }
    }
}