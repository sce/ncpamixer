#include "pa_card.hpp"
#include <stdio.h>

PaCard::PaCard()
{
    type = pa_object_t::CARD;
    monitor_stream = nullptr;
    pa_set_profile = pa_context_set_card_profile_by_index;
    pa_set_volume = nullptr;
    pa_set_mute = nullptr;
    pa_move = nullptr;
    active_profile = nullptr;
}


//void PaCard::clearProfiles()
//{
//    for (auto i = profiles->begin(); i != profiles->end(); i++) {
//        delete i->second;
//    }
//    profiles.clear();
//}

void PaCard::updateProfiles(pa_card_profile_info *pa_profiles, uint32_t n_profile)
{
    clearProfiles();
    for (uint32_t i = 0; i < n_profile; i++) {
        PaObjectAttribute *p = new PaObjectAttribute;
        snprintf(p->name, sizeof(p->name), "%s", pa_profiles[i].name);
        snprintf(p->description, sizeof(p->description), "%s",
             pa_profiles[i].description);
       profiles.push_back(p); 
    }
}
