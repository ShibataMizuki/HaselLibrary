#pragma once
#include"../Hasel/HaselAlias.h"
#include"../Hasel/Math/MathInc.h"
#include"../Hasel/Shape/AABB/AABB.h"
#include"shape/ShapeInc.h"

#include<memory>
#include<vector>

namespace hasel
{
	namespace cs2d
	{
		/// <summary>
		/// RigidBodyビルダー
		/// </summary>
		class RigidBodyMold
		{
			friend class RigidBody;
		private:
			//形状ビルダリスト
			std::vector<shape::Shape> shapes;
			// 属性リスト
			std::vector<int> attributes;
			// ユーザーデータ
			void* userdata;
			// 座標
			math::Vector2 pos;

			/// <summary>
			/// 末端関数
			/// </summary>
			void SetAttributes() { attributes.clear();}

		public:
			/// <summary>
			/// コンストラクタ
			/// </summary>
			RigidBodyMold();

			/// <summary>
			/// 座標設定関数
			/// </summary>
			/// <param name="pos">設定する座標</param>
			/// <returns>自身のインスタンス</returns>
			RigidBodyMold& SetPosition(const math::Vector2& pos);

			/// <summary>
			/// 形状を追加する
			/// </summary>
			/// <param name="shape">形状クラス</param>
			/// <returns>自身のインスタンス</returns>
			RigidBodyMold& AddShape(const shape::Shape& shape);

			/// <summary>
			/// 属性リスト設定関数
			/// </summary>
			/// <param name="head">設定する属性リスト</param>
			/// <param name="...tails">設定する属性リスト</param>
			/// <returns>自身のインスタンス</returns>
			template<class Head = int, class... Tails>
			RigidBodyMold& SetAttributes(const Head& head,const Tails&... tails)
			{
				SetAttributes(tails...);
				attributes.push_back(head);
				return *this;
			}

			/// <summary>
			/// 属性を追加する
			/// </summary>
			/// <param name="attribute">追加する属性</param>
			/// <returns>自身のインスタンス</returns>
			RigidBodyMold& AddAttribute(int attribute);

			/**
			@brief ユーザーデータ設定関数
			@param userdata 設定するユーザーデータ
			*/
			/// <summary>
			/// 任意データを設定する
			/// </summary>
			/// <param name="userdata">設定するデータ</param>
			/// <returns>自身のインスタンス</returns>
			RigidBodyMold& SetUserData(void* userdata);

			
			/// <summary>
			///	インスタンス作成関数
			/// </summary>
			/// <returns>作成された剛体</returns>
			sptr<RigidBody> MintShared()const;

			/// <summary>
			/// インスタンス作成関数
			/// </summary>
			/// <returns>作成された剛体</returns>
			uptr<RigidBody> MintUnique()const;

			/// <summary>
			/// インスタンス作成関数
			/// </summary>
			/// <returns>作成された剛体</returns>
			RigidBody* MintRaw()const;
		};

		/// <summary>
		/// 剛体クラス
		/// </summary>
		class RigidBody
		{
		private:
			// 座標
			math::Vector2 pos;
			// 図形リスト
			std::vector<shape::Shape> shapes;
			// 属性リスト
			std::vector<int> attributes;
			// ユーザーデータ
			void* userdata;
			// AABB
			mutable shape::AABB aabb;
			// AABBが変更されたか
			mutable bool isAABBChanged;

		public:
			/// <summary>
			/// コンストラクタ
			/// </summary>
			/// <param name="builder">ビルダー</param>
			RigidBody(const RigidBodyMold& mold);

			/// <summary>
			/// 座標を設定する
			/// </summary>
			/// <param name="pos">座標</param>
			void SetPosition(const math::Vector2& pos);

			/// <summary>
			/// 座標を取得する
			/// </summary>
			/// <returns>座標</returns>
			const math::Vector2& GetPosition()const;

			/// <summary>
			/// 属性を追加する
			/// </summary>
			/// <param name="attribute">追加する属性</param>
			void AddAttribute(int attribute);

			/// <summary>
			/// 属性を外す
			/// </summary>
			/// <param name="attribute">外す属性</param>
			void RemoveAttribute(int attribute);

			/**
			@brief 属性が存在するかどうか探す
			@param attribute 探す属性
			@return true  :存在する
					false :存在しない
			*/
			/// <summary>
			/// 属性が存在するかどうか検証する
			/// </summary>
			/// <param name="attribute">探す属性</param>
			/// <returns>
			/// true :存在する
			/// false:存在しない
			/// </returns>
			bool FindAttribute(int attribute)const;

			
			/// <summary>
			/// 属性リスト取得関数
			/// </summary>
			/// <returns>属性リスト</returns>
			const std::vector<int>& GetAttibutes()const;

			/// <summary>
			/// 任意データを設定する
			/// </summary>
			/// <param name="userdata">任意データ</param>
			void SetUserdata(void* userdata);

			/// <summary>
			/// 任意データを取得する
			/// </summary>
			/// <returns>任意データ</returns>
			void* GetUserdataRaw()const;

			/// <summary>
			/// 任意データを取得する
			/// Type 任意データの型
			/// </summary>
			/// <returns>任意データ</returns>
			template<typename Type>
			Type* GetUserdata()const
			{
				return static_cast<Type*>(userdata);
			}

			/// <summary>
			/// AABBを取得する
			/// </summary>
			/// <returns>AABB</returns>
			const shape::AABB& GetAABB()const;

			/// <summary>
			/// 形状リストを取得する
			/// </summary>
			/// <returns>形状リスト</returns>
			const std::vector<shape::Shape>& GetShapes()const;

		};
	}
}