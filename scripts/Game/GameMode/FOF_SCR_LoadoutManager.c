modded class SCR_LoadoutManager : GenericEntity
{
    protected override void EOnInit(IEntity owner)
    {       
        if (SCR_Global.IsEditMode())
            return;
        
        GetGame().GetCallqueue().CallLater(RemoveUsLoadout, 500, true);
    }
    
    private void RemoveUsLoadout()
    {
        bool foundOne = false;
        foreach (int index, SCR_BasePlayerLoadout loadout : m_aPlayerLoadouts)
        {
            if (loadout.GetLoadoutName().Contains("US"))
            {
                m_aPlayerLoadouts.Remove(index);
                return;
            }
        }
        
        if (!foundOne)
            GetGame().GetCallqueue().Remove(RemoveUsLoadout);

    }
}