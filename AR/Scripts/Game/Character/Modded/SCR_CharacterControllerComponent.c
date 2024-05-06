modded class SCR_CharacterControllerComponent {
	override void OnDeath(IEntity instigatorEntity, notnull Instigator instigator){
		super.OnDeath(instigatorEntity,instigator);
		if(Replication.IsServer()){				
			if(GetCharacter().GetFactionKey() == "FIA"){				
				SCR_BaseGameMode.enemies--;							
			}					
		}	
	}	
}