modded class SCR_AIGroup {
	
	protected ref array<vector> m_WalkPositions = {        
        Vector(4470.218, 13.96, 10925.851),
		Vector(4597.007, 25.955, 10721.83),
		Vector(4394.801, 12.136, 10675.313),
		Vector(4583.122, 15.992, 10505.501)	
    };
	
	IEntity currWP;
	IEntity nextWay;
	vector myZone;
	
	override void OnAgentAdded(AIAgent child){
		super.OnAgentAdded(child);
		//Pick a zone
		int randomIndex = Math.Floor(Math.RandomFloat01() * m_WalkPositions.Count());
		vector targetPosition = m_WalkPositions.Get(randomIndex);
		myZone = targetPosition;
				
		//First Waypoint
		vector nextMovePos = s_AIRandomGenerator.GenerateRandomPointInRadius(0, 135, targetPosition);		
		float theight = SCR_TerrainHelper.GetTerrainY(nextMovePos);
		nextMovePos[1] = theight;
		EntitySpawnParams paramsAI = new EntitySpawnParams();
		paramsAI.Transform[3] = nextMovePos;		
		Resource prefab = Resource.Load("{750A8D1695BD6998}Prefabs/AI/Waypoints/AIWaypoint_Move.et");		
		if (!prefab || !prefab.IsValid())
		return;
		currWP = GetGame().SpawnEntityPrefab(prefab, null, paramsAI);	
		AddWaypoint(SCR_AIWaypoint.Cast(currWP));
		
		//Second Waypoint
		vector nextMovePos2 = s_AIRandomGenerator.GenerateRandomPointInRadius(0, 135, myZone);	
		float theight2 = SCR_TerrainHelper.GetTerrainY(nextMovePos2);
		nextMovePos2[1] = theight2;		
		EntitySpawnParams paramsAI2 = new EntitySpawnParams();
		paramsAI2.Transform[3] = nextMovePos2;				
		nextWay = GetGame().SpawnEntityPrefab(prefab, null, paramsAI2);
		AddWaypoint(SCR_AIWaypoint.Cast(nextWay));
	}		
	override void OnWaypointCompleted(AIWaypoint wp){
		super.OnWaypointCompleted(wp);	
		RemoveWaypoint(wp);
		delete wp;		
		
		vector nextMovePos = s_AIRandomGenerator.GenerateRandomPointInRadius(0, 135, myZone);	
		float theight = SCR_TerrainHelper.GetTerrainY(nextMovePos);
		nextMovePos[1] = theight;			
		EntitySpawnParams paramsAI = new EntitySpawnParams();
		paramsAI.Transform[3] = nextMovePos;		
		Resource prefab = Resource.Load("{750A8D1695BD6998}Prefabs/AI/Waypoints/AIWaypoint_Move.et");		
		if (!prefab || !prefab.IsValid())
		return;
		nextWay = GetGame().SpawnEntityPrefab(prefab, null, paramsAI);
		AddWaypoint(SCR_AIWaypoint.Cast(nextWay));		
	}
};
