﻿using UnityEngine;
using UnityEngine.UI;

/// <summary>
/// 通用的卡牌单元格
/// </summary>
public class CardCell : MonoBehaviour
{
    private static Color UnSelectedColor = new Color(0xff, 0xff, 0xff);
    private static Color SelectedColor = new Color(0xb2,0xc3,0x4e);

    public delegate void CellClickHandler(string id,CardCellType type, CardCellStatus status);
    private event CellClickHandler _onCellSelected;

    /// <summary>
    /// 卡片、单位的id
    /// </summary>
    private string _cardId;
    private CardCellType _type;
    private Image _cardImg;
    private Text _indexText;
    private Text _nameText;
    private Image _selectedImg;
    /// <summary>
    /// 是否
    /// </summary>
    private bool _isSelectable;

    private CardCellStatus _status;
    /// <summary>
    /// 是否已经添加点击事件监听
    /// </summary>
    private bool _isAddedClickHander;

    void Awake()
    {
        this._cardImg = this.transform.FindChild("CardImg").GetComponent<Image>();
        this._indexText = this.transform.FindChild("IndexText").GetComponent<Text>();
        this._nameText = this.transform.FindChild("NameText").GetComponent<Text>();
        this._selectedImg = this.transform.FindChild("SelectedImg").GetComponent<Image>();
        this._isAddedClickHander = false;
        this._status = CardCellStatus.Unselected;
    }

    public CardCell()
    {

    }

    public void bindCellData(string id,CardCellType type)
    {
        this._cardId = id;
        this._type = type;
        UnitCfg cfg = UnitManager.getInatance().getUnitCfgBySysId(id);
        if ( cfg != null )
        {
            this.setNameText(cfg.name);
        }
        this._isSelectable = false;
    }

    public void setSelectable(bool value)
    {
        this._isSelectable = value;
    }

    public void setActive(bool value)
    {
        this.gameObject.SetActive(value);
    }

    /// <summary>
    /// 设置索引名称
    /// </summary>
    /// <param name="text"></param>
    public void setIndexText(string text)
    {
        this._indexText.text = text;
    }

    /// <summary>
    /// 临时使用，设置名称
    /// </summary>
    /// <param name="name"></param>
    public void setNameText(string name)
    {
        this._nameText.text = name;
    }

    /// <summary>
    /// 设置卡牌的图像
    /// </summary>
    /// <param name="textureName"></param>
    public void setCardImg(string textureName)
    {
        this._cardImg.sprite = Resources.Load<Sprite>(BattleSceneUtils.getCardTextureFullPath(textureName));
    }

    /// <summary>
    /// 添加选择、反选事件
    /// </summary>
    /// <param name="handler"></param>
    public void addClickEventHandler(CellClickHandler handler)
    {
        this._onCellSelected += handler;
        if ( !this._isAddedClickHander )
        {
            this._isAddedClickHander = true;
            UIEventListener.Get(this.gameObject).onClick += this.onCellClick;
        }
    }

    /// <summary>
    /// 移除选择、反选事件
    /// </summary>
    /// <param name="handler"></param>
    public void removeClickEventHandler(CellClickHandler handler)
    {
        this._onCellSelected -= handler;
        if ( this._isAddedClickHander )
        {
            this._isAddedClickHander = false;
            UIEventListener.Get(this.gameObject).onClick -= this.onCellClick;
        }
    }

    private void onCellClick(GameObject go)
    {
        this._status = (CardCellStatus)(1 - (int)this._status);
        this._onCellSelected(this._cardId, this._type, this._status);
        this._selectedImg.color = this._isSelectable && this._status == CardCellStatus.Selected ? SelectedColor : UnSelectedColor;
    }
}

public enum CardCellType
{
    Unit = 1,
    Card = 2,
}

public enum CardCellStatus
{
    /// <summary>
    /// 选择
    /// </summary>
    Selected = 1,
    /// <summary>
    /// 反选
    /// </summary>
    Unselected = 0,
}

