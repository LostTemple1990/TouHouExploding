﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

public class Player : IID
{
    /// <summary>
    /// 当前的B点
    /// </summary>
    private int _curBPoint;
    /// <summary>
    /// 当前的B点
    /// </summary>
    public int curBPoint
    {
        get { return this._curBPoint;  }
    }

    private int _bPointCeilingExtra;
    public int bPointCeilingExtra
    {
        get { return this._bPointCeilingExtra; }
    }

    private int _id;
    public int id
    {
        get
        {
            return this._id;
        }

        set
        {
            throw new NotImplementedException();
        }
    }

    /// <summary>
    /// 当前回合召唤计数
    /// </summary>
    private int _curSummoningCount;
    /// <summary>
    /// 当前回合召唤计数
    /// </summary>
    public int curSummoningCount
    {
        get
        {
            return this._curSummoningCount;
        }
    }

    private UnitPool _unitPool;
    public UnitPool unitPool
    {
        get { return this._unitPool; }
    }

    public void costBPoint(int value)
    {
        this._curBPoint -= value;
    }

    public Player()
    {
        this._id = IDProvider.getInstance().applyUnitId(this);
    }

    public void init()
    {
        this._unitPool = new UnitPool();
        this._unitPool.init();
    }

    public void resetBPoint()
    {
        this._curBPoint = BattleConsts.DEFAULT_BPOINT;
    }

    /// <summary>
    /// 从召唤池中召唤单位
    /// </summary>
    /// <param name="index"></param>
    /// <returns></returns>
    public string summonUnit(int index)
    {
        string id = this._unitPool.summonUnit(index);
        if ( id != "" )
        {
            this._curSummoningCount++;
        }
        return id;
    }

    public void reset()
    {
        this._curSummoningCount = 0;
        this._curBPoint = BattleConsts.DEFAULT_BPOINT;
    }
}