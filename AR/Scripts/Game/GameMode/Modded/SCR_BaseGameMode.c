modded class SCR_BaseGameMode{
	static int enemies = 0;	
	protected ref array<vector> m_SpawnPositions = {        
        Vector(4572.247, 19.144, 10978.319),
		Vector(4629.451, 22.916, 10876.448),
		Vector(4599.744, 17.426, 10806.613),
		Vector(4660.791, 22.238, 10652.397),
		Vector(4511.328, 17.312, 10561.189),
		Vector(4325.099, 11.775, 10643.854),
		Vector(4317.752, 0.357, 10783.094),
		Vector(4441.977, 4.769, 10819.276),
		Vector(4392.37, 5.028, 10849.561),
		Vector(4428.875, 6.578, 10964.334),
		Vector(4319.447, 1.734, 10915.565)				
    };	

	override void OnGameStart(){
		super.OnGameStart();
		if(Replication.IsServer()){			
			GetGame().GetCallqueue().CallLater(SpawnGuy,8000,true);					
		}
	}
	
	IEntity grp;	
	void SpawnGuy(){
		if(enemies<40){	
			int rv = Math.RandomInt(0,3);	
			if(rv == 0){			
				EntitySpawnParams paramsAI = new EntitySpawnParams();
				int randomIndex = Math.Floor(Math.RandomFloat01() * m_SpawnPositions.Count());
				vector targetPosition = m_SpawnPositions.Get(randomIndex);   	
				paramsAI.Transform[3] = targetPosition;		
				Resource prefab = Resource.Load("{000CD338713F2B5A}Prefabs/AI/Groups/Group_Base.et");		
				if (!prefab || !prefab.IsValid())
				return;
				grp = GetGame().SpawnEntityPrefab(prefab, null, paramsAI);											
				enemies++;
			}else if (rv == 1){
				EntitySpawnParams paramsAI = new EntitySpawnParams();
				int randomIndex = Math.Floor(Math.RandomFloat01() * m_SpawnPositions.Count());
				vector targetPosition = m_SpawnPositions.Get(randomIndex);   	
				paramsAI.Transform[3] = targetPosition;		
				Resource prefab = Resource.Load("{CE81583C828E5037}Prefabs/AI/Groups/Group_Base2.et");		
				if (!prefab || !prefab.IsValid())
				return;
				grp = GetGame().SpawnEntityPrefab(prefab, null, paramsAI);											
				enemies++;
			}else{
				EntitySpawnParams paramsAI = new EntitySpawnParams();
				int randomIndex = Math.Floor(Math.RandomFloat01() * m_SpawnPositions.Count());
				vector targetPosition = m_SpawnPositions.Get(randomIndex);   	
				paramsAI.Transform[3] = targetPosition;		
				Resource prefab = Resource.Load("{2B1D14C58E6BC75C}Prefabs/AI/Groups/Group_Base3.et");		
				if (!prefab || !prefab.IsValid())
				return;
				grp = GetGame().SpawnEntityPrefab(prefab, null, paramsAI);											
				enemies++;
			}
		}
	}	
}