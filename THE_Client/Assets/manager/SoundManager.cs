//------------------------------------------------------------------------------
// <auto-generated>
//     此代码由工具生成。
//     运行时版本:4.0.30319.34209
//
//     对此文件的更改可能会导致不正确的行为，并且如果
//     重新生成代码，这些更改将会丢失。
// </auto-generated>
//------------------------------------------------------------------------------
using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;


public class SoundManager
{
	private static SoundManager _instance;

	public static SoundManager getInstance()
	{
		if (_instance == null)
		{
			_instance = new SoundManager();
		}
		return _instance;
	}

	private List<GameObject> _soundObjList;
	private int _poolLen;

	public SoundManager ()
	{
		this._soundObjList = new List<GameObject> ();
		this._poolLen = 0;
	}

	public void playSound(string soundName,bool isLoop=false)
	{
		GameObject soundObj = new GameObject();
			/**if (this._poolLen > 0) 
			{
				soundObj = this._soundObjPool [--this._poolLen];
				this._soundObjPool.RemoveAt (this._poolLen);
			} 
			else 
			{
				soundObj = new GameObject();
			}*/
		AudioSource source = soundObj.AddComponent<AudioSource>() as AudioSource;
		AudioClip clip = Resources.Load(Global.SoundRootPath+soundName,typeof(AudioClip)) as AudioClip;
		source.clip = clip;
		source.loop = isLoop;
		source.Play();
	}

	public void playSound(string soundName,Vector3 pos,bool isLoop=false)
	{
		GameObject soundObj = this.createSoundObj();
		AudioSource source = soundObj.AddComponent<AudioSource>() as AudioSource;
		AudioClip clip = Resources.Load(Global.SoundRootPath+soundName,typeof(AudioClip)) as AudioClip;
		source.clip = clip;
		source.loop = isLoop;
		// 位置
		soundObj.transform.position = pos;
		source.Play();
	}
	// 暂停
	// 调音量
	// ------------全部删除
	// 
	
	private GameObject createSoundObj()
	{
		GameObject soundObj = new GameObject ();
		this._soundObjList.Add (soundObj);
		return soundObj;
		//DateTime nowTime = DateTime.Now;

		//Debug.Log (DateTime.Now.Subtract (nowTime).TotalMilliseconds);
	}
}

