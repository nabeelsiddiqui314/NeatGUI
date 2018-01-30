#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <memory>
#include <unordered_map>

namespace nt {
	template<typename Resource>
	class ResourceLoader
	{
	public:
		ResourceLoader(const std::string&  folder, const std::string&  extention)
		: m_folder("./assets/" + folder + "/")
		, m_extention("." + extention){}
		~ResourceLoader() {}
	public:
		void add(const std::string&  name) {
			Resource r;
			if (!r.loadFromFile(getFilename(name)) || exists(name)) {
				Resource fail;
				fail.loadFromFile(m_folder + "/fail/FAIL" + m_extention);
				m_resources.insert(std::make_pair(name, fail));
			}
			else m_resources.insert(std::make_pair(name, r));
		}

		Resource& get(const std::string&  name) {
			if (!exists(name)) {
				add(name);
			}
			return m_resources.at(name);
		}
	private:
		const std::string getFilename(const std::string&  name) {
			return (m_folder + name + m_extention);
		}

		bool exists(const std::string&  name) {
			return m_resources.find(name) != m_resources.end();
		}
	private:
		std::unordered_map<std::string, Resource> m_resources;

		std::string m_folder;
		std::string m_extention;
	};
}