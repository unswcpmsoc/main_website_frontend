<script lang="ts">
	import './layout.css';
	import AnnouncementBanner from '$lib/ui/AnnouncementBanner.svelte';
	import CPMSoc_Logo from '$lib/assets/CPMSoc_Logo.svg';
    import Navigation from '$lib/ui/Navigation.svelte'
    import Footer from "$lib/ui/Footer.svelte";

	let { children } = $props();
</script>

<svelte:head>
    <title>UNSW CPMSoc</title>
    <link rel="icon" href={CPMSoc_Logo} />
</svelte:head>

<div class="min-h-screen flex flex-col">
    <AnnouncementBanner />
    <Navigation />

    <main class="flex-1 h-full">
        {@render children()}
    </main>

    <Footer />
</div>
