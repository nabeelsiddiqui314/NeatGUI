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
		ResourceLoader(const std::string& folder, const std::string& extention)
		: m_folder("./assets/" + folder + "/")
		, m_extention("." + extention) {
			m_fail.loadFromFile(getFilename("/fail/FAIL"));
		}
		~ResourceLoader() {}
	public:
		void add(const std::string& filepath, const std::string& name) {
			Resource r;
			if (r.loadFromFile(getFilename(filepath))) {
				m_resources.insert(std::make_pair(name, r));
			}
			else
				m_resources.insert(std::make_pair(name, m_fail));
		}

		void add(const std::string& name) {
			Resource r;
			if (r.loadFromFile(getFilename(name))) {
				m_resources.insert(std::make_pair(name, r));
			}
			else
				m_resources.insert(std::make_pair(name, m_fail));
		}

		Resource& get(const std::string& name) {
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
		Resource m_fail;

		std::string m_folder;
		std::string m_extention;
		std::string m_filepath;
	};
}