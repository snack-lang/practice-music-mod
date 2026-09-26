#include <geode/geode.hpp>

using namespace geode::prelude;

class $modify(PlayLayer) {
	void onPracticeMode(bool isPractice) {
		PlayLayer::onPracticeMode(isPractice);

		auto enable = Mod::get()->getSettingValue<bool>("enable");
		if (!enable) return;

		if (isPractice) {
			if (m_level->m_musicTrack != 0) {
				FMODAudioEngine::get()->playMusic(m_level->m_musicTrack, true);
			}
		}
	}
};
